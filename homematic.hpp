/**
 * homematic.hpp
 *
 *  Created on: Jun 12, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifndef HOMEMATIC_HPP_
#define HOMEMATIC_HPP_

#include "Maschinentuer.hpp"

#define HM_PIN_OPEN	5
#define HM_PIN_CLOSE	4

#define HM_PIN_ACTIVE	LOW
#define HM_PIN_INACTIVE	HIGH

/**
 *
 */
void homematic_init(void);

/**
 *
 */
void homematic_close(void);

/**
 *
 */
void homematic_open(void);

#endif /* HOMEMATIC_HPP_ */
