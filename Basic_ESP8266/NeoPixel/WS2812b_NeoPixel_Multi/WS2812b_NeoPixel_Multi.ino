#include <Adafruit_NeoPixel.h>

#define PIN D2
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin();
}

void loop()
{
  int delayval = 500;
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    delay(delayval);
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    delay(delayval);
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(delayval);
  }
}
