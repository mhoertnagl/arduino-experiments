#include <LiquidUI.h>

LiquidUI::LiquidUI(LiquidCrystal_I2C *display, uint8_t cols, uint8_t rows)
{
  _display = display;
  _cols = cols;
  _rows = rows;
}

void LiquidUI::write(const char *text)
{
  _text = text;
  _len = strlen(text);
  _pos = 0;
}

void LiquidUI::loop()
{
  _display->setCursor(0, 0);

  for (uint8_t i = 0; i < _cols; i++)
  {
    _display->write(_text[(_pos + i) % _len]);
  }
  _pos++;
}