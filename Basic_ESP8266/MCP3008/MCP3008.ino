#include <MCP3008.h>
#define CS_PIN D8
#define CLOCK_PIN D5
#define MOSI_PIN D7
#define MISO_PIN D6
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  int val = adc.readADC(0); // read Channel 0 from MCP3008 ADC (pin 1)
  Serial.println(val);
  delay(1000);
}
