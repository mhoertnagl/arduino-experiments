#include <inttypes.h>
#include <LiquidCrystal_I2C.h>

class LiquidUI
{
public:
  LiquidUI(LiquidCrystal_I2C *display, uint8_t cols, uint8_t rows);
  void write(const char *text);
  void loop();

private:
  LiquidCrystal_I2C *_display;
  uint8_t _cols;
  uint8_t _rows;
  const char *_text;
  uint8_t _len;
  uint8_t _pos;
};