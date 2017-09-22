#include <Wire.h>
#include "Adafruit_MCP23017.h"

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)

// Output #0 is on pin 21 so connect an LED or whatever from that to ground

Adafruit_MCP23017 mcp;

int pin_led = 15; // IC ขา 8
int pin_sw = 8; // IC ขา 1
void setup() {  
  mcp.begin();      // use default address 0
  mcp.pinMode(pin_led, OUTPUT);
  mcp.pinMode(pin_sw,INPUT);
  mcp.pullUp(pin_sw,HIGH);
}


// flip the pin #0 up and down

void loop() {
  delay(100);
  int val = mcp.digitalRead(pin_sw);
  if(val==0){
    mcp.digitalWrite(pin_led, 1);
  }else if(val==1){
    mcp.digitalWrite(pin_led, 0);
  }
  
}
