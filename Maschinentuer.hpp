/**
 * Maschinentuer.hpp
 *
 *  Created on: Jun 9, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifndef MASCHINENTUER_HPP_
#define MASCHINENTUER_HPP_

#include <Arduino.h>

//#define DEBUG

#ifdef DEBUG

#endif /* DEBUG */

#define RANDOM_PIN	A7

#define OPENING_TIMEOUT_4 10000
#define OPENING_TIMEOUT_3  7500
#define OPENING_TIMEOUT_2  5000
#define OPENING_TIMEOUT_1  2500

#define USE_EEPROM
//#define USE_SPI_FLASH
//#define USE_SPI_SD

/**
 *
 */
void display_fly_in(char letters[4], int direction = 0);

/**
 *
 */
void display_fly_out(char letters[4], int direction = 0);

#endif /* MASCHINENTUER_HPP_ */
