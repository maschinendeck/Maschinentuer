## Maschinentür ## 

### RJ45 Pinout ###

  | Signal    | PIN | Color  | Color  | RaspiPin |  
  +-----------+-----+--------+--------+----------+  
  | GND       |  1  | violet | blue   |     6    |  
  | VIN (5V)  |  2  | grey   | green  |     2    |  
  | RX        |  3  | white  | yellow |     8    |  
  | TX        |  4  | black  | orange |    10    |  
  | DTR       |  5  | brown  |        |     X    |  
  | CTS       |  6  | red    |        |     X    |  
  | RST       |  7  | orange | red    |     7    |  
  | VCC (3V3) |  8  | yellow | brown  |     1    |  

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
 6. GND       (orange) GND (MOSFET GND)	6.1
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

### HM-Sender ###
 2. Open               D4
 3. Close              D5

