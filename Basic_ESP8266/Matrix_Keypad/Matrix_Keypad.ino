#include <Keypad.h>

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPin[4] = {D0, D1, D2, D3};
byte colPin[4] = {D4, D5, D6, D7};
Keypad keypad = Keypad(makeKeymap(keys), rowPin, colPin, 4, 4);

void setup()
{
  Serial.begin(115200);
}
void loop()
{
  char pressed = keypad.getKey();
  if (pressed)
  {
    Serial.println(pressed);
  }
}
