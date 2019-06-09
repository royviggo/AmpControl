#include "LcdDisplay.h"

// Setup for the LCD display
const int AMPC_LCD_COLS = 16;
const int AMPC_LCD_ROWS = 2;
const int AMPC_LCD_CHARSIZE = 0;

// Arduino pins for the LCD display
const int AMPC_LCD_PIN_RS = 8;
const int AMPC_LCD_PIN_EN = 9;
const int AMPC_LCD_PIN_D4 = 10;
const int AMPC_LCD_PIN_D5 = 11;
const int AMPC_LCD_PIN_D6 = 12;
const int AMPC_LCD_PIN_D7 = 13;

// Global vaiables
LcdDisplay display = LcdDisplay(AMPC_LCD_COLS, AMPC_LCD_ROWS, AMPC_LCD_CHARSIZE);
int counter = 0;

void setup()
{
    display.begin(AMPC_LCD_PIN_RS, AMPC_LCD_PIN_EN, AMPC_LCD_PIN_D4, AMPC_LCD_PIN_D5, AMPC_LCD_PIN_D6, AMPC_LCD_PIN_D7);
    display.print(0, 0, "Hello world!");
}

void loop()
{
    display.print(15, 0, String(++counter), false);
    delay(1000);
}
