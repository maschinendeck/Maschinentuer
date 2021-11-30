/**
 * storage_spi_flash.cpp
 *
 *  Created on: Jun 9, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifdef USE_SPI_FLASH
#include <Streaming.h>

#include "storage_spi_flash.hpp"

#include "Maschinentuer.hpp"
#include "rfid.hpp"

/**
 *
 */
void storage_init(void) {
	card_count = storage_read_card_count();

	if (card_count > 0) {
		storage_read_card(&master);
		master.valid = false;
	}

	Serial << F("initializing SPI-Flash") << endl;

	if (!SerialFlash.begin(FLASH_CS)) {
		Serial << F("unable to initialize SPI-Flash") << endl;
	} else {
		Serial << F(".. SPI-Flash init done ..") << endl;

		uint8_t id;
		SerialFlash.readID(&id);

		Serial << F("id: ") << id << endl;

		uint32_t capacity = SerialFlash.capacity(&id);

		Serial << F("capacity: ") << capacity << endl;

		unsigned char serialnumber[8];

		SerialFlash.readSerialNumber(serialnumber);

		char tmp[2];

		Serial << F("SerialNumber: ");

		for (uint8_t i = 0; i < 8; i++) {
			sprintf(tmp, "%.2X", serialnumber[i]);
			Serial << tmp << " ";
		}

		Serial << endl;
	}
}

/**
 *
 */
void storage_write_card_count(uint8_t count) {
	// TODO: implement
}

/**
 *
 */
uint8_t storage_read_card_count(void) {
	// TODO: implement

	return 0;
}

/**
 *
 */
void storage_write_card(rfid_card_t* rfid_card) {
	// TODO: implement
}

/**
 *
 */
bool storage_read_card(rfid_card_t* rfid_card) {
	// TODO: implement
	return false;
}

/**
 *
 */
bool storage_find_card(rfid_card_t* rfid_card) {
	// TODO: implement

	return false;
}

/**
 *
 */
void storage_list_cards_serial(void) {
	// TODO: implement
}

/**
 *
 */
uint8_t storage_get_next_card_id(void) {
	// TODO: implement

	return 0;
}

#endif /* USE_SPI_FLASH */

