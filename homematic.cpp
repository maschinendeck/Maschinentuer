/**
 * homematic.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: Christan Adams <morlac@morlac.de>
 */

#include <Arduino.h>

#include "homematic.hpp"

/**
 *
 */
void homematic_open(void) {
	digitalWrite(HM_PIN_OPEN, HM_PIN_ACTIVE);

	delay(500);

	digitalWrite(HM_PIN_OPEN, HM_PIN_INACTIVE);
}

/**
 *
 */
void homematic_close(void) {
	digitalWrite(HM_PIN_CLOSE, HM_PIN_ACTIVE);

	delay(500);

	digitalWrite(HM_PIN_CLOSE, HM_PIN_INACTIVE);
}

