#include "LcdDisplay.h"

LcdDisplay::LcdDisplay(uint8_t cols, uint8_t rows, uint8_t charSize) : cols(cols), rows(rows), charSize(charSize) {}

void LcdDisplay::begin(uint8_t pinRS, uint8_t pinEN, uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7)
{
    lcd = LiquidCrystal(pinRS, pinEN, pinD4, pinD5, pinD6, pinD7);
    lcd.begin(cols, rows, charSize);
}

void LcdDisplay::begin(uint8_t pinRS, uint8_t pinEN, uint8_t pinD0, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, 
                       uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7)
{
    lcd = LiquidCrystal(pinRS, pinEN, pinD0, pinD1, pinD2, pinD3, pinD4, pinD5, pinD6, pinD7);
    lcd.begin(cols, rows, charSize);
}

void LcdDisplay::print(uint8_t posX, uint8_t posY, String text, bool leftAligned)
{
    uint8_t textLength = text.length();

    if (!leftAligned)
        posX = textLength > posX ? 0 : posX - textLength + 1;

    if ((posX + textLength) > cols)
        text = text.substring(0, cols - posX);

    lcd.setCursor(posX, posY);
    lcd.print(text);
}
