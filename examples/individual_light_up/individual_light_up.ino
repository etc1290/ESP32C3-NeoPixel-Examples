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

  for(int i=0 ; i < NUMPIXELS ; i++){
    uint8_t green = map(i, 0, NUMPIXELS - 1, 0, 255);
    //pixels.setPixelColor(第幾顆, pixels.Color(Red, Green, Blue));
    pixels.setPixelColor(i, pixels.Color(150, green, 0));
    pixels.show();
    delay(500);
  }
}
