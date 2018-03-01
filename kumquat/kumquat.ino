/**
* Board Type: Mini Gorille CV Graphic / Arduino UNO
* Description: Alternate Firmware
*/

// Pins 
#define screen_MOSI_pin                 17
#define screen_MISO_pin                 '?'
#define sck 19
#define screen_externalCLock_pin        19 // ???
#define screen_internalCLockSelect_pin  19 // ???
#define screen_DataCommand_pin          14
#define screen_Reset_pin                15
#define screen_OLEDChipSelect_pin       16
#define screen_ReadWrite_pin            '?'


#define mgLEDPin      6
#define ardcoreLEDPin 3 

// Colors
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

// Option 1: use any pins but a little slower
Adafruit_SSD1351 tft = Adafruit_SSD1351(
  screen_OLEDChipSelect_pin,
  screen_DataCommand_pin,
  screen_MOSI_pin,
  sck,
  screen_Reset_pin);  

void setup() {
  Serial.begin(9600);
  Serial.println("setup complete");
  tft.begin();
  pinMode(ardcoreLEDPin, OUTPUT);  
  pinMode(mgLEDPin, OUTPUT);
}

void loop() {
  tft.fillScreen(RED);
  digitalWrite(mgLEDPin, HIGH);
  digitalWrite(ardcoreLEDPin, HIGH);
  tft.fillScreen(GREEN);
  digitalWrite(mgLEDPin, LOW);
  digitalWrite(ardcoreLEDPin, LOW);
//  tft.fillScreen(BLUE);
}
