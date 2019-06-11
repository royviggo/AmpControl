#include <Arduino.h>
#include "LcdDisplay.h"
#include "Button.h"

// Setup for the LCD display
const int AMPC_LCD_COLS = 16;
const int AMPC_LCD_ROWS = 2;
const int AMPC_LCD_CHARSIZE = 0;

// Arduino pins for the LCD display
const int AMPC_LCD_PIN_RS = 7;
const int AMPC_LCD_PIN_EN = 8;
const int AMPC_LCD_PIN_D4 = 9;
const int AMPC_LCD_PIN_D5 = 10;
const int AMPC_LCD_PIN_D6 = 11;
const int AMPC_LCD_PIN_D7 = 12;

// Button pins
const int AMPC_BUTTON_LEFT = 2;
const int AMPC_BUTTON_RIGHT = 3;
const int AMPC_BUTTON_SELECT = 4;
const int AMPC_BUTTON_SELECT_LONG = true;
const int AMPC_BUTTON_ACTIVE = false;

// Global vaiables
LcdDisplay display = LcdDisplay(AMPC_LCD_COLS, AMPC_LCD_ROWS, AMPC_LCD_CHARSIZE);

Button leftBtn = Button(AMPC_BUTTON_LEFT, AMPC_BUTTON_ACTIVE);
Button rightBtn = Button(AMPC_BUTTON_RIGHT, AMPC_BUTTON_ACTIVE);
Button selectBtn = Button(AMPC_BUTTON_SELECT, AMPC_BUTTON_ACTIVE, AMPC_BUTTON_SELECT_LONG);

void setup()
{
    display.begin(AMPC_LCD_PIN_RS, AMPC_LCD_PIN_EN, AMPC_LCD_PIN_D4, AMPC_LCD_PIN_D5, AMPC_LCD_PIN_D6, AMPC_LCD_PIN_D7);
    display.print(0, 0, "Hello world!");

    Serial.begin(115200);
    Serial.println("Setup Ok");
}

void loop()
{
    ButtonState leftBtnState = leftBtn.checkState();
    if (leftBtnState == NORMAL_CLICK)
        display.print(0, 1, "leftBtn!        ");

    ButtonState rightBtnState = rightBtn.checkState();
    if (rightBtnState == NORMAL_CLICK)
        display.print(0, 1, "rightBtn!       ");

    ButtonState selectBtnState = selectBtn.checkState();
    if (selectBtnState == NORMAL_CLICK)
        display.print(0, 1, "selectBtn!      ");
    if (selectBtnState == LONG_CLICK)
        display.print(0, 1, "selectBtn LONG! ");

    if (leftBtnState == NORMAL_CLICK || rightBtnState == NORMAL_CLICK ||
        selectBtnState == NORMAL_CLICK || selectBtnState == LONG_CLICK)
    {
        delay(800);
        display.print(0, 1, "                ");
    }
}
