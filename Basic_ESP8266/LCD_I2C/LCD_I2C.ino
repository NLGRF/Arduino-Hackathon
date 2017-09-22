#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); //ถ้าจอไม่แสดงผล ให้ลองเปลี่ยน 0x3F เป็น 0x27
void setup()
{
  lcd.begin(16,2);
  lcd.backlight(); // เปิดไฟ backlight
  lcd.setCursor(4, 0); // ไปที่ตัวอักษรที่ 4 บรรทัดที่ 0
  lcd.print("LCD ESP8266");
  lcd.setCursor(2, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
  lcd.print("BY ArduinoALL");
}

void loop()
{
}

// https://mikeyancey.com/hamcalc/lcd_characters.php

/* byte customChar0[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000
  };
  byte customChar1[8] = {
    0b11100,
    0b11100,
    0b11100,
    0b11111,
    0b11111,
    0b11111,
    0b11110,
    0b00000
  };
  lcd.createChar(1, customChar0);
  lcd.createChar(2, customChar1);*/
