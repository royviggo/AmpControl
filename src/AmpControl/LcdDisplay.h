#ifndef LCDDISPLAY_H
#define LCDDISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LcdDisplay
{
private:
    LiquidCrystal lcd = LiquidCrystal(0, 0, 0, 0, 0, 0);
    uint8_t cols;
    uint8_t rows;
    uint8_t charSize;

public:
    LcdDisplay(uint8_t cols, uint8_t rows, uint8_t charSize = LCD_5x8DOTS);
    void begin(uint8_t pinRS, uint8_t pinEN, uint8_t pinD4, uint8_t pinD5, uint8_t pinD6,uint8_t pinD7);
    void begin(uint8_t pinRS, uint8_t pinEN, uint8_t pinD0, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7);
    void print(uint8_t posX, uint8_t posY, String text, bool leftAligned = true);
};

#endif
