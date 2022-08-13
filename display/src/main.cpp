#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidUI.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidUI ui(&lcd, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  ui.write("Hallo, Katzen! +++ ");
}

void loop()
{
  ui.loop();
  delay(800);
}
