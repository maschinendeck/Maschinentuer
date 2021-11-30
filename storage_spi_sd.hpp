/**
 * storage_spi_sd.hpp
 *
 *  Created on: Jun 12, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifndef STORAGE_SPI_SD_HPP_
#define STORAGE_SPI_SD_HPP_

#ifdef USE_SPI_SD

//https://www.arduino.cc/en/Reference/SD
#include "SD.h"

#define SD_CS		10
//#define SD_SPI_SPEED 1 // MHz

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

#endif /* USE_SPI_SD */

#endif /* STORAGE_SPI_SD_HPP_ */
