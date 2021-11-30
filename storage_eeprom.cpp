/**
 * storage_eeprom.cpp
 *
 *  Created on: Jun 9, 2019
 *      Author: Christan Adams <morlac@morlac.de>
 */

#include "storage_eeprom.hpp"

#include <EEPROM.h>

#include "Streaming.h"

#include "Maschinentuer.hpp"

uint8_t card_count;

/**
 *
 */
void storage_init(void) {
	card_count = storage_read_card_count();

	if (card_count > 0) {
		storage_read_card(&master);
	}
}

/**
 *
 */
void storage_write_card_count(uint8_t count) {
	eeprom_write_byte(ADDR_NUM_CARDS, count);

	card_count = count;
}

/**
 *
 */
uint8_t storage_read_card_count(void) {
	return eeprom_read_byte(ADDR_NUM_CARDS);
}

/**
 *
 */
void storage_write_card(rfid_card_t* rfid_card) {
	eeprom_write_block(rfid_card, (void*)(ADDR_CARDS_LIST + (rfid_card->id * sizeof(rfid_card_t))), sizeof(rfid_card_t));
}

/**
 *
 */
bool storage_read_card(rfid_card_t* rfid_card) {
	uint8_t card_id = rfid_card->id;

//	Serial << F("searching for id [") << card_id << F("]") << endl;

	eeprom_read_block(rfid_card, (void*)(ADDR_CARDS_LIST + (card_id * sizeof(rfid_card_t))), sizeof(rfid_card_t));

//	Serial << F("storage_read_card: [");
//	print_card_serial(rfid_card);
//	Serial << F("]") << endl;

	return (rfid_card->id == card_id);
}

/**
 *
 */
bool storage_find_card(rfid_card_t* rfid_card) {
	rfid_card_t test_card = {0};

	for (int card_id = 0; card_id < card_count; card_id++) {
		test_card.id = card_id;

		if (storage_read_card(&test_card) && !memcmp(&(test_card.uid), &(rfid_card->uid), 4)) {
//			Serial << F("storage_find_card success") << endl;

			memcpy(rfid_card, &test_card, sizeof(rfid_card_t));

			return true;
//		} else {
//			Serial << F("not matching:[");
//			print_uid_serial(rfid_card);
//			Serial << F("] vs [");
//			print_uid_serial(&test_card);
//			Serial << F("]") << endl;
		}
	}

	return false;
}

/**
 *
 */
void storage_list_cards_serial(void) {
	rfid_card_t rfid_card;
	char temp[10] = {0};
	uint8_t i, j;

	Serial << F("  id, valid, uid                , name") << endl;

	for (i = 0; i < card_count; i++) {
		eeprom_read_block(&rfid_card, (void*)(ADDR_CARDS_LIST + (i * sizeof(rfid_card_t))), sizeof(rfid_card_t));

		rfid_print_card_serial(&rfid_card);

		Serial << endl;
	}
}

/**
 *
 */
uint8_t storage_get_next_card_id(void) {
	rfid_card_t rfid_card;

	for (int card_id = 1; card_id < card_count; card_id++) {
		rfid_card.id = card_id;
		storage_read_card(&rfid_card);

		if (!rfid_card.valid) {
			return rfid_card.id;
		}
	}

	return card_count;
}

