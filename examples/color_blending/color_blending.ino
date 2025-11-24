// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

#define PIN        3
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB);

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  //pixels.setPixelColor(第幾顆, pixels.Color(Red, Green, Blue));
  pixels.setPixelColor(1, pixels.Color(150, 0, 0));
  pixels.show();
  delay(500);

  pixels.setPixelColor(2, pixels.Color(0, 150, 0));
  pixels.show();
  delay(500);

  pixels.setPixelColor(3, pixels.Color(0, 0, 150));
  pixels.show();
  delay(500);

  pixels.setPixelColor(4, pixels.Color(150, 150, 150));
  pixels.show();
  delay(500);
}
