#include <Arduino.h>

#define buzzer 6
#define LED 3
#define button 2

volatile int buttonState;

void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  if (buttonState == 0) // if the button is pressed
  {
    tone(buzzer, 440);
    delay(500);
    tone(buzzer, 262);
    delay(500);
    digitalWrite(LED, HIGH); // the LED lights up
  }
  else
  {
    noTone(buzzer);
    digitalWrite(LED, LOW); // the LED is off
  }
  delay(100);
}