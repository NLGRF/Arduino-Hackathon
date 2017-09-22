#include <Adafruit_NeoPixel.h>
 
#define PIN D2
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() 
{
 pixels.begin();
}
 
void loop() 
{
 int delayval = 500; // delay for half a second
 // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
 
 for(int i=0;i<NUMPIXELS;i++)
 {
 // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
 pixels.setPixelColor(i, pixels.Color(0,255,0));
 pixels.show();
 delay(delayval);
 pixels.setPixelColor(i, pixels.Color(255,0,0));
 pixels.show();
 delay(delayval);
 pixels.setPixelColor(i, pixels.Color(0,0,255));
 pixels.show();
 delay(delayval);
 pixels.setPixelColor(i, pixels.Color(255,255,255));
 pixels.show();
 delay(delayval);
 }
}
