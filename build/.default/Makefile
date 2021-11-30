ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/Maschinentuer.cpp.o \

PLATFORM_CORE_OBJS = \
	core/HardwareSerial3.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/wiring_analog.c.o \
	core/Print.cpp.o \
	core/main.cpp.o \
	core/wiring_digital.c.o \
	core/HardwareSerial1.cpp.o \
	core/WInterrupts.c.o \
	core/Tone.cpp.o \
	core/WMath.cpp.o \
	core/wiring_shift.c.o \
	core/USBCore.cpp.o \
	core/new.cpp.o \
	core/Stream.cpp.o \
	core/wiring.c.o \
	core/wiring_pulse.c.o \
	core/wiring_pulse.S.o \
	core/PluggableUSB.cpp.o \
	core/WString.cpp.o \
	core/HardwareSerial.cpp.o \
	core/IPAddress.cpp.o \
	core/hooks.c.o \
	core/CDC.cpp.o \
	core/abi.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/HT1632/1.0.3/Adafruit_HT1632.cpp.o \
	libraries/MFRC522/1.4.3/src/MFRC522.cpp.o \
	libraries/MFRC522/1.4.3/src/MFRC522Extended.cpp.o \
	libraries/Wire/src/utility/twi.c.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/SPI/src/SPI.cpp.o \
	libraries/Adafruit_GFX_Library/1.4.2/Adafruit_GFX.cpp.o \
	libraries/Adafruit_GFX_Library/1.4.2/Adafruit_SPITFT.cpp.o \
	libraries/Adafruit_GFX_Library/1.4.2/glcdfont.c.o \
	libraries/SdFat/1.0.16/src/FatLib/FatFile.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/FatFileLFN.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/FatFilePrint.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/FatFileSFN.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/FatVolume.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/FmtNumber.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/StdioStream.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/fstream.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/istream.cpp.o \
	libraries/SdFat/1.0.16/src/FatLib/ostream.cpp.o \
	libraries/SdFat/1.0.16/src/MinimumSerial.cpp.o \
	libraries/SdFat/1.0.16/src/SdCard/SdSpiCard.cpp.o \
	libraries/SdFat/1.0.16/src/SdCard/SdSpiCardEX.cpp.o \
	libraries/SdFat/1.0.16/src/SdCard/SdioCardEX.cpp.o \
	libraries/SdFat/1.0.16/src/SdCard/SdioTeensy.cpp.o \
	libraries/SdFat/1.0.16/src/SpiDriver/SdSpiESP8266.cpp.o \
	libraries/SdFat/1.0.16/src/SpiDriver/SdSpiParticle.cpp.o \
	libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSAM3X.cpp.o \
	libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSTM32.cpp.o \
	libraries/SdFat/1.0.16/src/SpiDriver/SdSpiTeensy3.cpp.o \
	libraries/Adafruit_LED_Backpack_Library/1.1.6/Adafruit_LEDBackpack.cpp.o \
	libraries/SoftwareSerial/src/SoftwareSerial.cpp.o \
	libraries/HID/src/HID.cpp.o \

TARGETS = \
	Maschinentuer.hex \

all: $(TARGETS)

Maschinentuer.hex: Maschinentuer.elf
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./Maschinentuer.elf" "./Maschinentuer.hex"

Maschinentuer.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./Maschinentuer.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) -- *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-size" -A "./Maschinentuer.elf"

project/Maschinentuer.cpp.o: ../../Maschinentuer.cpp project/Maschinentuer.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

project/Maschinentuer.cpp.d: ;

-include project/Maschinentuer.cpp.d 


core/HardwareSerial3.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/HardwareSerial2.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial0.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/wiring_analog.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/Print.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/main.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/wiring_digital.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/HardwareSerial1.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/WInterrupts.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/Tone.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/WMath.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/wiring_shift.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/USBCore.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/new.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/Stream.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/wiring.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_pulse.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/WString.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d

core/HardwareSerial.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/IPAddress.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/hooks.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/CDC.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/abi.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d



libraries/HT1632/1.0.3/Adafruit_HT1632.cpp.o: /home/adams/.arduinocdt/libraries/HT1632/1.0.3/Adafruit_HT1632.cpp libraries/HT1632/1.0.3/Adafruit_HT1632.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/HT1632/1.0.3/Adafruit_HT1632.cpp.d: ;

-include libraries/HT1632/1.0.3/Adafruit_HT1632.cpp.d

libraries/MFRC522/1.4.3/src/MFRC522.cpp.o: /home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src/MFRC522.cpp libraries/MFRC522/1.4.3/src/MFRC522.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/MFRC522/1.4.3/src/MFRC522.cpp.d: ;

-include libraries/MFRC522/1.4.3/src/MFRC522.cpp.d

libraries/MFRC522/1.4.3/src/MFRC522Extended.cpp.o: /home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src/MFRC522Extended.cpp libraries/MFRC522/1.4.3/src/MFRC522Extended.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/MFRC522/1.4.3/src/MFRC522Extended.cpp.d: ;

-include libraries/MFRC522/1.4.3/src/MFRC522Extended.cpp.d

libraries/Wire/src/utility/twi.c.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/Wire/src/Wire.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/SPI/src/SPI.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

libraries/Adafruit_GFX_Library/1.4.2/Adafruit_GFX.cpp.o: /home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2/Adafruit_GFX.cpp libraries/Adafruit_GFX_Library/1.4.2/Adafruit_GFX.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/Adafruit_GFX_Library/1.4.2/Adafruit_GFX.cpp.d: ;

-include libraries/Adafruit_GFX_Library/1.4.2/Adafruit_GFX.cpp.d

libraries/Adafruit_GFX_Library/1.4.2/Adafruit_SPITFT.cpp.o: /home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2/Adafruit_SPITFT.cpp libraries/Adafruit_GFX_Library/1.4.2/Adafruit_SPITFT.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/Adafruit_GFX_Library/1.4.2/Adafruit_SPITFT.cpp.d: ;

-include libraries/Adafruit_GFX_Library/1.4.2/Adafruit_SPITFT.cpp.d

libraries/Adafruit_GFX_Library/1.4.2/glcdfont.c.o: /home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2/glcdfont.c libraries/Adafruit_GFX_Library/1.4.2/glcdfont.c.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/Adafruit_GFX_Library/1.4.2/glcdfont.c.d: ;

-include libraries/Adafruit_GFX_Library/1.4.2/glcdfont.c.d

libraries/SdFat/1.0.16/src/FatLib/FatFile.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/FatFile.cpp libraries/SdFat/1.0.16/src/FatLib/FatFile.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/FatFile.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/FatFile.cpp.d

libraries/SdFat/1.0.16/src/FatLib/FatFileLFN.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/FatFileLFN.cpp libraries/SdFat/1.0.16/src/FatLib/FatFileLFN.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/FatFileLFN.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/FatFileLFN.cpp.d

libraries/SdFat/1.0.16/src/FatLib/FatFilePrint.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/FatFilePrint.cpp libraries/SdFat/1.0.16/src/FatLib/FatFilePrint.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/FatFilePrint.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/FatFilePrint.cpp.d

libraries/SdFat/1.0.16/src/FatLib/FatFileSFN.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/FatFileSFN.cpp libraries/SdFat/1.0.16/src/FatLib/FatFileSFN.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/FatFileSFN.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/FatFileSFN.cpp.d

libraries/SdFat/1.0.16/src/FatLib/FatVolume.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/FatVolume.cpp libraries/SdFat/1.0.16/src/FatLib/FatVolume.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/FatVolume.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/FatVolume.cpp.d

libraries/SdFat/1.0.16/src/FatLib/FmtNumber.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/FmtNumber.cpp libraries/SdFat/1.0.16/src/FatLib/FmtNumber.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/FmtNumber.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/FmtNumber.cpp.d

libraries/SdFat/1.0.16/src/FatLib/StdioStream.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/StdioStream.cpp libraries/SdFat/1.0.16/src/FatLib/StdioStream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/StdioStream.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/StdioStream.cpp.d

libraries/SdFat/1.0.16/src/FatLib/fstream.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/fstream.cpp libraries/SdFat/1.0.16/src/FatLib/fstream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/fstream.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/fstream.cpp.d

libraries/SdFat/1.0.16/src/FatLib/istream.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/istream.cpp libraries/SdFat/1.0.16/src/FatLib/istream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/istream.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/istream.cpp.d

libraries/SdFat/1.0.16/src/FatLib/ostream.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/FatLib/ostream.cpp libraries/SdFat/1.0.16/src/FatLib/ostream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/FatLib/ostream.cpp.d: ;

-include libraries/SdFat/1.0.16/src/FatLib/ostream.cpp.d

libraries/SdFat/1.0.16/src/MinimumSerial.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/MinimumSerial.cpp libraries/SdFat/1.0.16/src/MinimumSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/MinimumSerial.cpp.d: ;

-include libraries/SdFat/1.0.16/src/MinimumSerial.cpp.d

libraries/SdFat/1.0.16/src/SdCard/SdSpiCard.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SdCard/SdSpiCard.cpp libraries/SdFat/1.0.16/src/SdCard/SdSpiCard.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SdCard/SdSpiCard.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SdCard/SdSpiCard.cpp.d

libraries/SdFat/1.0.16/src/SdCard/SdSpiCardEX.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SdCard/SdSpiCardEX.cpp libraries/SdFat/1.0.16/src/SdCard/SdSpiCardEX.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SdCard/SdSpiCardEX.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SdCard/SdSpiCardEX.cpp.d

libraries/SdFat/1.0.16/src/SdCard/SdioCardEX.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SdCard/SdioCardEX.cpp libraries/SdFat/1.0.16/src/SdCard/SdioCardEX.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SdCard/SdioCardEX.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SdCard/SdioCardEX.cpp.d

libraries/SdFat/1.0.16/src/SdCard/SdioTeensy.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SdCard/SdioTeensy.cpp libraries/SdFat/1.0.16/src/SdCard/SdioTeensy.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SdCard/SdioTeensy.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SdCard/SdioTeensy.cpp.d

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiESP8266.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SpiDriver/SdSpiESP8266.cpp libraries/SdFat/1.0.16/src/SpiDriver/SdSpiESP8266.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiESP8266.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SpiDriver/SdSpiESP8266.cpp.d

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiParticle.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SpiDriver/SdSpiParticle.cpp libraries/SdFat/1.0.16/src/SpiDriver/SdSpiParticle.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiParticle.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SpiDriver/SdSpiParticle.cpp.d

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSAM3X.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSAM3X.cpp libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSAM3X.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSAM3X.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSAM3X.cpp.d

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSTM32.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSTM32.cpp libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSTM32.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSTM32.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SpiDriver/SdSpiSTM32.cpp.d

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiTeensy3.cpp.o: /home/adams/.arduinocdt/libraries/SdFat/1.0.16/src/SpiDriver/SdSpiTeensy3.cpp libraries/SdFat/1.0.16/src/SpiDriver/SdSpiTeensy3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SdFat/1.0.16/src/SpiDriver/SdSpiTeensy3.cpp.d: ;

-include libraries/SdFat/1.0.16/src/SpiDriver/SdSpiTeensy3.cpp.d

libraries/Adafruit_LED_Backpack_Library/1.1.6/Adafruit_LEDBackpack.cpp.o: /home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6/Adafruit_LEDBackpack.cpp libraries/Adafruit_LED_Backpack_Library/1.1.6/Adafruit_LEDBackpack.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/Adafruit_LED_Backpack_Library/1.1.6/Adafruit_LEDBackpack.cpp.d: ;

-include libraries/Adafruit_LED_Backpack_Library/1.1.6/Adafruit_LEDBackpack.cpp.d

libraries/SoftwareSerial/src/SoftwareSerial.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src/SoftwareSerial.cpp libraries/SoftwareSerial/src/SoftwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/SoftwareSerial/src/SoftwareSerial.cpp.d: ;

-include libraries/SoftwareSerial/src/SoftwareSerial.cpp.d

libraries/HID/src/HID.cpp.o: /home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src/HID.cpp libraries/HID/src/HID.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/adams/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/variants/standard" -I"/home/adams/.arduinocdt/libraries/HT1632/1.0.3" -I"/home/adams/.arduinocdt/libraries/MFRC522/1.4.3/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/EEPROM/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/Wire/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_GFX_Library/1.4.2" -I"/home/adams/.arduinocdt/libraries/SdFat/1.0.16/src" -I"/home/adams/.arduinocdt/libraries/Adafruit_LED_Backpack_Library/1.1.6" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/home/adams/.arduinocdt/packages/arduino/hardware/avr/1.6.23/libraries/HID/src" "$<" -o "$@"

libraries/HID/src/HID.cpp.d: ;

-include libraries/HID/src/HID.cpp.d

