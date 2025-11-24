// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

#define PIN        3
#define NUMPIXELS 25

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800 );

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0 ; i < NUMPIXELS ; i++){
    uint8_t hue = map(i, 0, NUMPIXELS - 1, 0, 65535);
    //pixels.setPixelColor(第幾顆, pixels.Color(Red, Green, Blue));
    pixels.setPixelColor(i, pixels.ColorHSV(hue));
    pixels.show();
    delay(500);
  }
}
