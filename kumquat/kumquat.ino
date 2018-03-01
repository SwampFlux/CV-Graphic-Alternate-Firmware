/**
* Board Type: Mini Gorille CV Graphic / Arduino UNO
* Description: Alternate Firmware
*/

// Pins 
#define mosiPin       17
#define sclk          19
#define dc            14
#define resetPin      15
#define cs            16
#define mgLEDPin      6
#define ardcoreLEDPin 3 

// Colors
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

// Option 1: use any pins but a little slower
Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, mosiPin, sclk, resetPin);  

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
  delay(500);
  tft.fillScreen(GREEN);
  digitalWrite(mgLEDPin, LOW);
  digitalWrite(ardcoreLEDPin, LOW);
  delay(500);
  tft.fillScreen(BLUE);
  delay(500);
}
