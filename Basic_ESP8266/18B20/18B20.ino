#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.print("Temperature for Device 1 is: ");
  Serial.println(sensors.getTempCByIndex(0));
}
