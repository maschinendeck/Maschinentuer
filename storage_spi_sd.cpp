/**
 * storage_spi_sd.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: Christian Adams <morlac@morlac.de>
 */

#ifdef USE_SPI_SD

#include <Arduino.h>

#include <Streaming.h>

#include "Maschinentuer.hpp"

#include "storage_spi_sd.hpp"

// global for card size
uint32_t cardSize;

/**
 *
 */
void storage_init(void) {
	// SD Setup
	if (!card.init(SPI_FULL_SPEED, SD_CS)) {
		Serial << F("cardBegin failed") << endl;
	} else {
		uint32_t t = millis();

		Serial << F("\ninit time: ") << t << F(" ms") << endl;
		Serial << F("\nCard type: ");

		switch (card.type()) {
		case SD_CARD_TYPE_SD1:
			Serial << F("SD1");
			break;

		case SD_CARD_TYPE_SD2:
			Serial << F("SD2");
			break;

		case SD_CARD_TYPE_SDHC:
			if (cardSize < 70000000) {
				Serial << F("SDHC");
			} else {
				Serial << F("SDXC");
			}
			break;

		default:
			Serial << F("Unknown");
		}

		Serial << endl;

		// Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
		if (!volume.init(card)) {
			Serial << F("Could not find FAT16/FAT32 partition.") << endl << F("Make sure you've formatted the card") << endl;
		} else {
			Serial << F("Clusters:          ");
			Serial << (volume.clusterCount()) << endl;

			Serial << F("Blocks x Cluster:  ");
			Serial << (volume.blocksPerCluster()) << endl;

			Serial << ("Total Blocks:      ");
			Serial << (volume.blocksPerCluster() * volume.clusterCount()) << endl << endl;

			// print the type and size of the first FAT-type volume
			uint32_t volumesize;
			Serial << F("Volume type is:    FAT");
			Serial << (volume.fatType(), DEC) << endl;

			volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
			volumesize *= volume.clusterCount();       // we'll have a lot of clusters
			volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)

			Serial << F("Volume size (Kb):  ");
			Serial << (volumesize) << endl;

			Serial << F("Volume size (Mb):  ");
			volumesize /= 1024;
			Serial << (volumesize) << endl;

			Serial << F("Volume size (Gb):  ");
			Serial << ((float)volumesize / 1024.0) << endl;

			Serial << F("\nFiles found on the card (name, date and size in bytes): ") << endl;
			root.openRoot(volume);

			// list all files in the card with date and size
			root.ls(LS_R | LS_DATE | LS_SIZE);
		}

		Serial << F("init done ..") << endl;
	}
}

#endif /* USE_SPI_SD */
