/**
 * storage_eeprom.hpp
 *
 *  Created on: Jun 9, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifndef STORAGE_EEPROM_HPP_
#define STORAGE_EEPROM_HPP_

#include "Maschinentuer.hpp"
#include "rfid.hpp"

#define ADDR_NUM_CARDS 0x00
#define ADDR_CARDS_LIST 0x01

extern uint8_t card_count;
extern rfid_card_t master;

/**
 *
 */
void storage_init(void);

/**
 *
 */
void storage_write_card_count(uint8_t count);

/**
 *
 */
uint8_t storage_read_card_count(void);

/**
 *
 */
void storage_write_card(rfid_card_t* rfid_card);

/**
 *
 */
bool storage_read_card(rfid_card_t* rfid_card);

/**
 *
 */
bool storage_find_card(rfid_card_t* rfid_card);

/**
 *
 */
void storage_list_cards_serial(void);

/**
 *
 */
uint8_t storage_get_next_card_id(void);

#endif /* STORAGE_EEPROM_HPP_ */
