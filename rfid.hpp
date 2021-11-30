/**
 * rfid.hpp
 *
 *  Created on: Jun 12, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifndef RFID_HPP_
#define RFID_HPP_

#include <Arduino.h>

#include <MFRC522.h>

#define RFID_POWER	7

#define RFID_POWER_ON	HIGH
#define RFID_POWER_OFF	LOW

//#define RFID_POWER_ON	LOW
//#define RFID_POWER_OFF	HIGH

#define RFID_CS 	9
#define RFID_RST	8

#define ADD_CARD_TIMEOUT 30000 // 30 seconds

#define SCAN_FOR_CARD_TIMEOUT 30000 // 30 seconds

/**
 *
 */
typedef struct rfid_card {
	uint8_t id;
	bool valid;
	uint8_t uid[4];
	char name[11];
} rfid_card_t;

/**
 *
 */
void rfid_init(void);

/**
 *
 */
void rfid_power(uint8_t status);

/**
 *
 */
void rfid_power_on(void);

/**
 *
 */
void rfid_power_off(void);

/**
 *
 */
void rfid_print_uid_serial(uint8_t uid[4]);

/**
 *
 */
bool rfid_uid_string_to_uid(String uid_string, uint8_t uid[4]);

/**
 *
 */
void rfid_print_name_serial(char name[11]);

/**
 *
 */
void rfid_print_card_serial(rfid_card_t* rfid_card);

/**
 *
 */
bool rfid_scan_for_card(unsigned long timeout, uint8_t uid[4]);

/**
 *
 */
bool rfid_scan_for_master(unsigned long timeout);

/**
 *
 */
void scan_for_card(bool* listen_for_card, bool* opening);

#endif /* RFID_HPP_ */
