/**
 * rfid.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#include <Arduino.h>
#include <errno.h>

#include <Streaming.h>

#include "Maschinentuer.hpp"

#include "rfid.hpp"
#include "homematic.hpp"

#ifdef USE_EEPROM
#include "storage_eeprom.hpp"
#endif

#ifdef USE_SPI_FLASH
#include "storage_spi_flash.hpp"
#endif /* USE_SPI_FLASH*/

#ifdef SPI_SPI_SD
#include "storage_spi_sd.hpp"
#endif

// https://github.com/miguelbalboa/rfid
MFRC522 mfrc522(RFID_CS, RFID_RST);  // Create MFRC522 instance

rfid_card_t master = {0};
uint8_t card_scanned[4];

bool card_present;

/**
 *
 */
void rfid_init(void) {
	// RFID Setup
//	Serial << F("initializing RFID ..") << endl;

	mfrc522.PCD_Init();             		// Init MFRC522
//	mfrc522.PCD_DumpVersionToSerial();      // Show details of PCD - MFRC522 Card Reader details

//	Serial << F(".. RFID init done ..") << endl;
}

/**
 *
 */
void rfid_power(uint8_t status) {
	pinMode(RFID_POWER, OUTPUT);

	digitalWrite(RFID_POWER, status);
}

/**
 *
 */
void rfid_power_on(void) {
	rfid_power(RFID_POWER_ON);

	rfid_init();
}

/**
 *
 */
void rfid_power_off(void) {
	rfid_power(RFID_POWER_OFF);
}

/**
 *
 */
void rfid_print_uid_serial(uint8_t uid[4]) {
	char temp[6] = {0};

	for (int i = 0; i < 4; i++) {
		snprintf(temp, 5, "0x%02X", uid[i]);
		Serial << temp << (i < 3 ? F(" ") : F(""));
	}
}

/**
 *
 */
bool rfid_uid_string_to_uid(String uid_string, uint8_t uid[4]) {
	// <0xXX 0xXX 0xXX 0xXX>
	// 01    6    1    1
	//            1    6
	if (uid_string.length() == 4 + 1 + 4 + 1 + 4 + 1 + 4) {
		// Serial << F("uid_string: [") << uid_string << F("]") << endl;

		uint8_t i, offset;
		String byte_string;

		for (i = 0, offset = 0; i < 4; i++, offset += 5) {
			byte_string = uid_string.substring(offset, offset + 4);

			errno = 0;
			uid[i] = strtol(byte_string.c_str(), NULL, 16);

			if (errno) {
				return false;
			}

			// Serial << F("byte_string: [") << byte_string << F("] => [") << uid[i] << F("]") << endl;
		}

		return true;
	}

	return false;
}

/**
 *
 */
void rfid_print_name_serial(char name[11]) {
	char temp[12] = {0};

	for (int i = 0; i < 11; i++) {
		snprintf(temp, 2, "%c", name[i]);
		Serial << temp;
	}
}

/**
 *
 */
void rfid_print_card_serial(rfid_card_t* rfid_card) {
	char temp[5] = {0};

	snprintf(temp, 4, "%03d", rfid_card->id);
	Serial << F(" ") << temp << F(", ");

	Serial << (rfid_card->valid ? F(" true") : F("false")) << F(", ");

	rfid_print_uid_serial(rfid_card->uid);

	Serial << F(", ");

	rfid_print_name_serial(rfid_card->name);
}

/**
 *
 */
bool rfid_scan_for_card(unsigned long timeout, uint8_t uid[4]) {
	unsigned long stamp = millis();

	while((millis() - stamp) < timeout) {
		if (card_present) {
			memcpy(uid, card_scanned, 4);

			// Serial << F("card present: [");
			// rfid_print_uid_serial(uid);
			// Serial << F("]") << endl;

			return true;
		}

//		mfrc522.PCD_Reset();

		if (mfrc522.PICC_IsNewCardPresent()) {
//			Serial << F("found card") << endl;

			if (mfrc522.PICC_ReadCardSerial()) {
//				Serial << F("found uid: [");
//				rfid_print_uid_serial(mfrc522.uid.uidByte);
//				Serial << F("]") << endl;

				if (memcmp(&(master.uid), &(mfrc522.uid.uidByte), 4)) {
					memcpy(uid, &(mfrc522.uid.uidByte), 4);

					// Serial << F("found card: [");
					// rfid_print_uid_serial(uid);
					// Serial << F("]") << endl;

//					mfrc522.PICC_HaltA(); // tell card to Stop processing / responding for now

					return true;
				} else {
					// Serial << F("master.uid: [");
					// rfid_print_uid_serial(master.uid);
					// Serial << F("]") << endl;

					mfrc522.PICC_HaltA(); // tell mastercard to Stop processing / responding for now
				}

//				mfrc522.PICC_HaltA();
//			} else {
//				Serial << F("no new serial") << endl;
			}
//		} else {
//			Serial << F("no new card") << endl;
		}

//		mfrc522.PICC_HaltA();
	}

//	mfrc522.PICC_HaltA();

	return false;
}

/**
 *
 */
bool rfid_scan_for_master(unsigned long timeout) {
	unsigned long stamp = millis();
	card_present = false;

//	mfrc522.PCD_Reset();

	while ((millis() - stamp) < timeout) {
		if (mfrc522.PICC_IsNewCardPresent()) {
			if (mfrc522.PICC_ReadCardSerial()) {
				if (!memcmp(&(master.uid), &(mfrc522.uid.uidByte), 4)) {
					// Serial << F("found mastercard: [");
					// rfid_print_uid_serial(mfrc522.uid.uidByte);
					// Serial << F("]") << endl;

					mfrc522.PICC_HaltA(); // tell mastercard to stop processing  / responding for now

					return true;
				} else {
					memcpy(&(card_scanned), &(mfrc522.uid.uidByte), 4);

					// Serial << F("found 2nd card: [");
					// rfid_print_uid_serial(card_scanned);
					// Serial << F("]") << endl;

					// mfrc522.PICC_HaltA(); // tell 2nd card to stop processing / responding for now

					card_present = true;
				}

				// mfrc522.PICC_HaltA();
			}
		}
	}

	// mfrc522.PICC_HaltA();

	return false;
}

/**
 *
 */
void scan_for_card(bool* listen_for_card, bool* opening) {
	// Serial << F("listening for cards") << endl;

	// Look for new cards
	if (mfrc522.PICC_IsNewCardPresent()) {
		// Serial << F("found card") << endl;

		if (mfrc522.PICC_ReadCardSerial()) {
			rfid_card_t rfid_card = {0};

			memcpy(&(rfid_card.uid), &(mfrc522.uid.uidByte), 4);

			// Serial << F("found serial: ");
			// print_uid_serial(&rfid_card);
			// Serial << endl;

			if (storage_find_card(&rfid_card) && (rfid_card.id != 0) && rfid_card.valid) {
				Serial << F("open") << endl;

				homematic_open();

				*opening = false;
				*listen_for_card = false;

				display_fly_in("open");

				delay(2500);

				display_fly_in("Deck");
			}

			// mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
		}

		// mfrc522.PICC_HaltA();
	}

	// mfrc522.PICC_HaltA();
}
