/**
 * Maschinentuer.cpp
 *
 * Created on: Jun 9, 2019
 *     Author: Christian Adams <morlac@morlac.de>
 */

#include <avr/pgmspace.h>

// Workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=34734
#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif /*PROGMEM */

// for c++-style cout and "<<" operator
#include <Streaming.h>

#include <Wire.h>
#include <SPI.h>

#include "Maschinentuer.hpp"
#include "rfid.hpp"
#include "homematic.hpp"

extern uint8_t card_count;

extern rfid_card_t master;
extern MFRC522 mfrc522;

#ifdef USE_EEPROM
#include "storage_eeprom.hpp"
#endif /* USE_EEPROM */

#ifdef USE_SPI_SD
#include "storage_spi_sd.hpp"
#endif /* USE_SPI_SD */

#ifdef USE_SPI_FLASH
#include "storage_spi_flash.hpp"
#endif /* USE_SPI_FLASH */

#include <Adafruit_LEDBackpack.h>

// https://github.com/adafruit/Adafruit_LED_Backpack/blob/master/examples/quadalphanum/quadalphanum.ino
Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();

unsigned long time;
bool listen_for_card = false;
bool opening = false;

static int8_t code[4] = {'f', 'f', 'f', 'f'};

/**
 *
 */
void soft_restart(void) {
	asm volatile ("jmp 0");
}

/**
 *
 */
String invalid_input(String serial_in) {
	return ("400 invalid input: [") + serial_in + ("]");
}

/**
 *
 */
String invalid_state(String serial_in) {
	return ("500 invalid state: [") + serial_in + ("]");
}

/**
 *
 */
String return_success() {
	return F("200 success");
}

/**
 *
 */
String return_failed() {
	return F("400 failed");
}
/**
 *
 */
String failed(void) {
	display_fly_in("fail");

	delay(2500);

	//display_fly_in("Deck");

	display.clear();
	display.writeDisplay();

	return return_failed();
}

/**
 *
 */
void not_implemented_yet(int line = 0) {
	Serial << F("not implemented yet");

	if (line != 0) {
		Serial << " line: " << line;
	}

	Serial << endl;
}

/**
 * direction = 0 - right to left
 * direction = 1 - left to right
 */
void display_fly_in(char letters[4], int direction = 0) {
	int8_t i, j;

	if (direction == 0) {
		for (j = 0; j <= 3; j++) {
			for (i = 3; i >= j; i--) {
				display.writeDigitAscii(i, letters[j], false);
				display.writeDigitAscii(i + 1, ' ', false);
				display.writeDisplay();
				delay(100);
			}
		}
	} else {
		for (j = 3; j >= 0; j--) {
			for (i = 0; i <= j; i++) {
				display.writeDigitAscii(i, letters[j], false);
				display.writeDigitAscii(i - 1, ' ', false);
				display.writeDisplay();
				delay(100);
			}
		}
	}
}

/**
 *
 */
void display_fly_out(char letters[4], int direction = 0) {
	int8_t i, j;

	if (direction == 0) {

	} else {

	}

//	not_implemented_yet();
}

/**
 *
 */
void setup(void) {
	Serial.begin(9600);

	pinMode(RANDOM_PIN, INPUT);
	Serial.setTimeout(10000);

//	Serial << F("initializing SPI ..") << endl;

	SPI.begin();

	rfid_init();

  homematic_init(); 

	rfid_power_off();

	storage_init();

//	Serial << F(".. SPI init done ..") << endl;

	// Display Setup
//	Serial << F("initializing display ..") << endl;

	display.begin(0x70);  // pass in the address

	display_fly_in("MDOS");

	delay(2500);

	display_fly_out("MDOS");

	delay(2500);

	display.clear();
	display.writeDisplay();

//	Serial << F(".. display init done ..") << endl;

	Serial << F("ready") << endl;
}

/**
 *
 */
String serial_open(String serial_in) {
	opening = true;

	// enable RFID-Reader
	listen_for_card = true;
	rfid_power_on();

	// initialize random-generator with analog-pin
	randomSeed(analogRead(RANDOM_PIN) + analogRead(RANDOM_PIN) + analogRead(RANDOM_PIN) + analogRead(RANDOM_PIN));

	// generated random 4 digits "code" and show on display
	for (int i=0; i < 4; i++) {
		code[i] = random(10);

		display.writeDigitAscii(i, 48 + code[i], false);
	}

	// set Timer
	time = millis();

	display.writeDisplay();

	// tell Raspi we're now waiting for code-input
	return F("200 waiting");
}

/**
 *
 */
String serial_close(String serial_in) {
	homematic_close();

	return F("200 closed");
}

/**
 * input: <code xxxx>
 */
String serial_code(String serial_in) {
	// <code xxxx>
	if (opening) {
		if (serial_in.length() == 5 + 4) {
			String input_code = serial_in.substring(5, 5 + 4);
			String code_result = "";

			for (int i = 0; i < 4; i++) {
				if (strtol(input_code.substring(i, i + 1).c_str(), NULL, 10) == code[i]) {
					code_result += F("t");
				} else {
					code_result += F("f");
				}
			}

			// erase code from memory
			memset(&code, 'f', 4);

			opening = false;

			if (code_result.equals(F("tttt"))) {
				display_fly_in("open");

				homematic_open();

				delay(3000);

				return F("200 code success");
			} else {
				return failed();
			}
		} else {
			// erase code from memory
			memset(&code, 'f', 4);

			opening = false;

			display_fly_in("fail");

			delay(3000);

			return invalid_input(serial_in);
		}
	} else {
		return invalid_state("");
	}
}

/**
 * input: <clear_cards>
 */
String serial_clear_cards(String serial_in) {
	storage_write_card_count(0);

	display_fly_in("ClCa");

	delay(2500);

	return return_success();
}

/**
 * 	<enable_card scan>
 *  <enable_card id ddd>
 * 	<enable_card uid 0xXX 0xXX 0xXX 0xXX>
 * 	<enable_card uid 0xXX 0xXX 0xXX 0xXX nnnnnnnnnnnn> // name[11]
 */
String serial_enable_card(String serial_in) {
	if (serial_in.substring(12, 12 + 4).equals("scan")) {
		// <enable_card scan>
		rfid_power_on();

		display_fly_in("mast");

		delay(2500);

		if (card_count > 0) {
			rfid_card_t rfid_card = {0};

			if (rfid_scan_for_master(SCAN_FOR_CARD_TIMEOUT)) {
				display_fly_in("card");

				if (rfid_scan_for_card(SCAN_FOR_CARD_TIMEOUT, rfid_card.uid)) {
//					Serial << F("enabling card : [");
//					print_uid_serial(rfid_card.uid);
//					Serial << F("]") << endl;

					if (storage_find_card(&rfid_card)) {
						rfid_card.valid = true;

						display_fly_in("EnCa");
					} else {
						rfid_card.valid = true;
						rfid_card.id = storage_get_next_card_id();

						if (rfid_card.id == card_count) {
							storage_write_card_count(card_count + 1);
						}

						display_fly_in("AdCa");
					}

					storage_write_card(&rfid_card);

					rfid_power_off();

					delay(2500);

					return return_success();
				} else {
					rfid_power_off();

					return failed();
				}
			} else {
				rfid_power_off();

				return failed();
			}
		} else { // if (card_count > 0)
			// Serial << F("card_count < 0") << endl;

			bool timeout = true;

			master.id = 0;
			master.valid = true;

			// ensure memory area for string is clean
			memset(&(master.name), 0, 11);

			// set name
			memcpy(&(master.name), "Master", 6);

			time = millis();

			while ((millis() - time) < ADD_CARD_TIMEOUT) {
				if (mfrc522.PICC_IsNewCardPresent()) {
					if (mfrc522.PICC_ReadCardSerial()) {
						memcpy(&(master.uid), &(mfrc522.uid.uidByte), 4);

						storage_write_card(&master);
						storage_write_card_count(1);

						timeout = false;
						break;
					}
				}
			}

			mfrc522.PICC_HaltA();

			if (timeout) {
				rfid_power_off();

				return failed();
			} else {
				display_fly_in("AdMa");

				rfid_power_off();

				delay(2500);

				return return_success();
			}
		}
	} else if (serial_in.substring(12, 12 + 2).equals(F("id"))) {
		// <enable_card id ddd>
		rfid_card_t rfid_card = {0};

		String id_string = serial_in.substring(12 + 3 , 12 + 3 + 3);

		// Serial << F("id_string: [") << id_string << F("]") << endl;

		rfid_card.id = strtol(id_string.c_str(), NULL, 10);

		// print_card_serial(&rfid_card);
		// Serial << endl;

		if (storage_read_card(&rfid_card) && !rfid_card.valid) {
			rfid_card.valid = true;

			// print_card_serial(&rfid_card);
			// Serial << endl;

			storage_write_card(&rfid_card);

			display_fly_in("EnCa");

			delay(2500);

			return return_success();
		} else { // if (storage_read_card(&rfid_card) && !rfid_card.valid)
			Serial << F("invalid card-id or card alread active") << endl;

			return failed();
		}
	} else if (serial_in.substring(12, 12 + 3).equals(F("uid"))) {
		// <enable_card uid 0xXX 0xXX 0xXX 0xXX>
		// <enable_card uid 0xXX 0xXX 0xXX 0xXX nnnnnnnnnnn>
		rfid_card_t rfid_card = {0};

		String uid_string = serial_in.substring(12 + 4);

		Serial << F("uid_string: [") << uid_string << F("]") << endl;

		if (uid_string.length() == 4 + 1 + 4 + 1 + 4 + 1 + 4) {
			// <enable_card uid 0xXX 0xXX 0xXX 0xXX>
			if (rfid_uid_string_to_uid(uid_string, rfid_card.uid)) {
				if (storage_find_card(&rfid_card)) {
					// (invalid?) card found - activating
					if (!rfid_card.valid) {
//						print_card_serial(&rfid_card);
//						Serial << endl;

						rfid_card.valid = true;

//						print_card_serial(&rfid_card);
//						Serial << endl;

						storage_write_card(&rfid_card);
					} else {
						Serial << F("card already active") << endl;
					}

					return return_success();
				} else { // if (storage_find_card(&rfid_card))
					// no card found - adding new (nameless)
					rfid_card.id = storage_get_next_card_id();
					rfid_card.valid = true;

//					print_card_serial(&rfid_card);
//					Serial << endl;

					storage_write_card(&rfid_card);

					if (rfid_card.id == card_count) {
						storage_write_card_count(card_count + 1);
					}

					return return_success();
				}
			} else { // if (rfid_uid_string_to_uid(uid_string, rfid_card.uid))
				return invalid_input(uid_string);
			}
		} else if (uid_string.length() > 4 + 1 + 4 + 1 + 4 + 1 + 4) {
			// <enable_card uid 0xXX 0xXX 0xXX 0xXX nnnnnnnnnnn>
			// TODO: implement
			not_implemented_yet(__LINE__);

			rfid_power_off();

			return F("not implemented yet");
		} else {
			rfid_power_off();

			return invalid_input(serial_in);
		}
	} else {
		rfid_power_off();

		return invalid_input(serial_in);
	}
}

/**
 *
 */
String serial_set_cardname(String serial_in) {
	// <set_cardname ddd ccccccccccc>
	rfid_card_t rfid_card = {0};

	String card_id = serial_in.substring(13, 13 + 3);
	String card_name = serial_in.substring(13 + 4, 13 + 4 + 11);

	rfid_card.id = strtol(card_id.c_str(), NULL, 10);

	// Serial << F("card-id  : [") << card_id << F("]") << endl;
	// Serial << F("card-name: [") << card_name << F("]") << endl;

	if (storage_read_card(&rfid_card) && rfid_card.valid) {
		// print_card_serial(&rfid_card);
		// Serial << endl;

		// clear old card-name
		memset(&(rfid_card.name), 0, 11);

		// set new card-name
		memcpy(&(rfid_card.name), card_name.c_str(), (card_name.length() <= 11 ? card_name.length() : 11));

		// print_card_serial(&rfid_card);
		// Serial << endl;

		storage_write_card(&rfid_card);

		return return_success();
	} else {
		// print_card_serial(&rfid_card);
		// Serial << endl;

		return F("card not found or invalid");
	}
}

/**
 *
 */
String serial_disable_card(String serial_in) {
	if (serial_in.substring(0, 0 + 4).equals(F("scan"))) {
		// <enable_card scan>
		display_fly_in("mast");

		delay(2500);

		rfid_card_t rfid_card = {0};

		if (rfid_scan_for_master(SCAN_FOR_CARD_TIMEOUT)) {
			display_fly_in("card");

			if (rfid_scan_for_card(SCAN_FOR_CARD_TIMEOUT, rfid_card.uid)) {
				// Serial << F("enabling card : [");
				// print_uid_serial(rfid_card.uid);
				// Serial << F("]") << endl;

				if (storage_find_card(&rfid_card)) {
					rfid_card.valid = false;

					display_fly_in("DaCa");

					storage_write_card(&rfid_card);

					delay(2500);

					display_fly_in("Deck");

					return return_success();
				} else {
					return failed();
				}
			} else {
				return failed();
			}
		} else {
			return failed();
		}
	} else if (serial_in.substring(0, 0 + 2).equals(F("id"))) {
		// <id ddd>
		rfid_card_t rfid_card = {0};

		String id_string = serial_in.substring(3 + 1, 3 + 1 + 3);

		// Serial << F("id: [") << id_string << F("]");

		rfid_card.id = strtol(id_string.c_str(), NULL, 10);

		// print_card_serial(&rfid_card);
		// Serial << endl;

		if (storage_read_card(&rfid_card) && rfid_card.valid) {
			rfid_card.valid = false;

			// print_card_serial(&rfid_card);
			// Serial << endl;

			storage_write_card(&rfid_card);

			return return_success();
		} else {
			Serial << F("card-id invalid or card not valid") << endl;

			return return_failed();
		}
	} else if (serial_in.substring(0, 0 + 3).equals(F("uid"))) {
		// <uid 0xXX 0xXX 0xXX 0xXX>
		rfid_card_t rfid_card = {0};

		String uid_string = serial_in.substring(0 + 3 + 1);

		// Serial << F("uid_string: [") << uid_string << F("]") << endl;

		if (uid_string.length() == 4 + 1 + 4 + 1 + 4 + 1 + 4) {
			if (rfid_uid_string_to_uid(uid_string, rfid_card.uid)) {
				// print_card_serial(&rfid_card);
				// Serial << endl;

				if (storage_find_card(&rfid_card) && rfid_card.valid) {
					rfid_card.valid = false;

					// print_card_serial(&rfid_card);
					// Serial << endl;

					storage_write_card(&rfid_card);

					return return_success();
				} else {
					Serial << F("card-id invalid or card invalid") << endl;

					return failed();
				}
			} else {
				return invalid_input(uid_string);
			}
		} else {
			return invalid_input(uid_string);
		}
	} else {
		display_fly_in("Deck");

		return invalid_input(serial_in);
	}
}

/**
 *
 */
String serial_list_cards(String serial_in) {
	Serial << F("Found [") << card_count << F("] cards") << endl;

	storage_list_cards_serial();

	return return_success();
}

/**
 *
 */
String serial_display(String serial_in) {
	String letters = serial_in.substring(8, 8 + 4);

	display_fly_in((char*) letters.c_str());

	delay(2500);

	display_fly_out((char*) letters.c_str());

	display.clear();
	display.writeDisplay();

	return return_success();
}

/**
 *
 */
String serial_display_off(void) {
	display.clear();
	display.writeDisplay();

	return return_success();
}

/**
 *
 */
void loop(void) {
	if (Serial.available() > 0) {
		String serial_in = Serial.readStringUntil('\n');
		String result = "";

		if (serial_in.equals(F("off"))) {
			result = serial_display_off();
		} else if (serial_in.substring(0, 0 + 4).equals(F("open"))) {
			result = serial_open(serial_in);
		} else if (serial_in.equals(F("close"))) {
			result = serial_close(serial_in);
		} else if (serial_in.substring(0, 0 + 4).equals(F("code"))) {
			result = serial_code(serial_in);

			display_fly_in("Deck");

			delay(2500);

			display_fly_out("Deck");

			delay(2500);

			display.clear();
			display.writeDisplay();

			rfid_power_off();
		} else if (serial_in.substring(0, 0 + 7).equals(F("display"))) {
			result = serial_display(serial_in);
		} else if (serial_in.equals(F("clear_cards"))) {
			result = serial_clear_cards(serial_in);
		} else if (serial_in.substring(0, 0 + 11).equals(F("enable_card"))) {
			result = serial_enable_card(serial_in);
		} else if (serial_in.substring(0, 0 + 12).equals(F("disable_card"))) {
			result = serial_disable_card(serial_in.substring(12 + 1));
		} else if (serial_in.substring(0, 0 + 12).equals(F("set_cardname"))) {
			result = serial_set_cardname(serial_in);
		} else if (serial_in.substring(0, 0 + 10).equals(F("list_cards"))) {
			result = serial_list_cards(serial_in);
		} else if (serial_in.equals(F("reboot"))) {
			soft_restart();
		} else {
			result = "400 invalid command: [" + serial_in + "]";
		}

		Serial << result << endl;
	}

	// set dots when opening
	if (opening) {
		unsigned long current = millis() - time;

		if (current > OPENING_TIMEOUT_1) {
			display.writeDigitAscii(0, 48 + code[0], true);
		}

		if (current > OPENING_TIMEOUT_2) {
			display.writeDigitAscii(1, 48 + code[1], true);
		}

		if (current > OPENING_TIMEOUT_3) {
			display.writeDigitAscii(2, 48 + code[2], true);
		}

		if (current > OPENING_TIMEOUT_4) {
			display.writeDigitAscii(3, 48 + code[3], true);
		}

		display.writeDisplay();

		if (current > OPENING_TIMEOUT_4) {
			// erase code from memory
			memset(&code, 'f', 4);

			opening = false;
			listen_for_card = false;

			rfid_power_off();

			Serial << F("408 open_timeout") << endl;

			display_fly_in("fail");

			delay(2500);

			display_fly_in("Deck");
		}
	}

	if (listen_for_card) {
		scan_for_card(&listen_for_card, &opening);
	}
}
