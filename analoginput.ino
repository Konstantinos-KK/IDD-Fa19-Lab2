/*
  http://www.arduino.cc/en/Tutorial/AnalogInput
  http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
*/

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A5;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
float sensorValue = 0;  // variable to store the value coming from the sensor
float a = 0;

void setup() {
  lcd.begin(16, 2);
  sensorValue = analogRead(sensorPin);
  lcd.print(sensorValue);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  a = (5*sensorValue)/1024;
  lcd.print(a);
  delay(1000);
  lcd.clear();
  
}
