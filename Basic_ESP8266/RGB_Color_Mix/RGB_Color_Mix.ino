int red = D6;
int green = D7;
int blue = D8;

// the setup routine runs once when you press reset:
void setup()
{
  // initialize the digital pin as an output.
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(red, LOW); // turn the LED on
  delay(1000); // wait for a second
  digitalWrite(red, HIGH); // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
  digitalWrite(green, LOW); // turn the LED on
  delay(1000); // wait for a second
  digitalWrite(green, HIGH); // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
  digitalWrite(blue, LOW); // turn the LED on
  delay(1000); // wait for a second
  digitalWrite(blue, HIGH); // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
  delay(1000); // wait for a second
  analogWrite(blue, 500);
  analogWrite(red, 500);
  delay(1000); // wait for a second
}
