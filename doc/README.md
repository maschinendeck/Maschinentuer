## Maschinentür ## 

### RJ45 Pinout ###

  | Signal     | PIN | Color  | RaspiPin |  
  +------------+-----+--------+----------+  
  | GND        |  1  | brown  |     9    | 
  | VIN (20V)  |  2  | red    |     X    | Step Up Output
  | AVR_A/PI_Y |  3  |        |     X    | Bus Driver
  | AVR_Y/PI_A |  4  |        |     X    | Bus Driver
  | AVR_Z/PI_B |  5  |        |     X    | Bus Driver
  | AVR_B/PI_Z |  6  |        |     X    | Bus Driver
  | RST        |  7  | red    |     7    |  
  | FTDI(3V3)  |  8  |        |     X    |  
  
+ blk -> Raspi Pin 14 (20V GND)

!!! Arduino Seite Layoutfehler - In aktueller Version funktioniert deshalb das Flashkabel nicht !!!

### Pi Bus Driver ###

Pin 1 = Pin 1 von Treiber IC
  | Signal     | Bustreiber Pin | Color  | RaspiPin |  
  +------------+----------------+--------+----------+  
  | VCC (5V)   |  1             | green  |     2    |  
  | RX         |  2             | orange |     10   |  
  | TX         |  3             | yellow |     8    | Bus Driver
  | GND        |  4             | blue   |     6    | Bus Driver


### Display Pinout ###
 source: [https://learn.adafruit.com/adafruit-led-backpack/0-54-alphanumeric]
 
 Display                Arduino
 1. SCL  (i2c) (blue)   A5
 2. SDA  (i2c) (violet) A4
 3. GND        (grey)   GND
 4. VCC  (5V)  (white)  RAW
 5. Vi2c (3V3) (black)  VCC

 Both Vi2c and Vcc MUST be connected to 3 to 5VDC! Vcc is for the LED driver power, Vi2c is what sets the logic level for communication to the chip.

### RFID Pinout ###
 [github](https://github.com/miguelbalboa/rfid)
 1. SPI-CS    (grey)   D9		6.2
 2. SPI-CLK   (white)  D13		6.4
 3. SPI-MOSI  (black)  D11		6.6
 4. SPI-MISO  (brown)  D12		6.5
 5. IRQ       (red)
 6. GND       (orange) D7 (Enable)	6.1
 7. RST       (yellow) D8		6.3	
 8. VCC (3V3) (green)  VCC

### SPI-Flash Pinout ###
 1. SPI-MOSI  D11
 2. SPI-CLK   D13
 3. GND       DNG
 4. SPI-MISO  D12
 5. SPI-Cs    D10
 6. VCC (3V3) VCC

### SD-Card Pinout ###
 
 1. GND       (blue)   GND
 2. SPI-MISO  (green)  D12
 3. SPI-CLK   (yellow) D13
 4. SPI-MOSI  (orange) D11
 5. SPI-CS    (red)    D10
 6. VCC (3V3) (brown)  VCC

### Relayboard ###
 1. VCC					5V
 2. Reserve (Relay 4)	D2
 3. Reserve (Relay 3)	D3
 4. Open (Relay 2)		D4
 5. Close (Relay 1)		D5
 6. GND					GND