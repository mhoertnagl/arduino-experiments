#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>

#define DHT11_PIN 7

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht11 dht;

char s[16];

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int status = dht.read(DHT11_PIN);
  switch (status)
  {
  case DHTLIB_OK:
    lcd.setCursor(0, 0);
    sprintf(s, "Temp: %d dC", dht.temperature);
    lcd.print(s);
    lcd.setCursor(0, 1);
    sprintf(s, "Humid: %d %%", dht.humidity);
    lcd.print(s);
    break;
  case DHTLIB_ERROR_CHECKSUM:
    break;
  case DHTLIB_ERROR_TIMEOUT:
    break;
  default:
    break;
  }
  delay(500);
}