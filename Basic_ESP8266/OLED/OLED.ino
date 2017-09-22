#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

void setup()
{
Wire.begin();
oled.init(); // สั่งให้จอ Oled เริ่มทำงาน
oled.clearDisplay(); // ล้างภาพหน้าจอ
oled.setTextXY(0,0); // เลื่อน cursor ไปที่บรรทัดที่ 0 ตำแหน่งที่ 0
oled.putString("Welcome To");
oled.setTextXY(1,5); // เลื่อน cursor ไปที่บรรทัดที่ 1 ตำแหน่งที่ 5
oled.putString("ArduinoALL");
oled.setTextXY(3,0); // เลื่อน cursor ไปที่บรรทัดที่ 3 ตำแหน่งที่ 0
oled.putString("ESP8266 NodeMCu");
oled.setTextXY(4,0); // เลื่อน cursor ไปที่บรรทัดที่ 4 ตำแหน่งที่ 10
oled.putString("Tutor");
}

void loop()
{
}
