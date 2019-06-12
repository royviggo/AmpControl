#include <Arduino.h>
#include "LcdDisplay.h"
#include "Button.h"
#include "RotaryEncoder.h"

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
const int AMPC_BUTTON_ACTIVE_PINS = false;

// Rotary encoder
const int AMPC_ENCODER_PINA = 5;
const int AMPC_ENCODER_PINB = 6;
const int AMPC_ENCODER_ACTIVE_PINS = false;

// Global variables
LcdDisplay display = LcdDisplay(AMPC_LCD_COLS, AMPC_LCD_ROWS, AMPC_LCD_CHARSIZE);

Button leftBtn = Button(AMPC_BUTTON_LEFT, AMPC_BUTTON_ACTIVE_PINS);
Button rightBtn = Button(AMPC_BUTTON_RIGHT, AMPC_BUTTON_ACTIVE_PINS);
Button selectBtn = Button(AMPC_BUTTON_SELECT, AMPC_BUTTON_ACTIVE_PINS, AMPC_BUTTON_SELECT_LONG);

RotaryEncoder encoder = RotaryEncoder(AMPC_ENCODER_PINA, AMPC_ENCODER_PINB, AMPC_ENCODER_ACTIVE_PINS);

uint8_t encoderValue = 0;

void setup()
{
    display.begin(AMPC_LCD_PIN_RS, AMPC_LCD_PIN_EN, AMPC_LCD_PIN_D4, AMPC_LCD_PIN_D5, AMPC_LCD_PIN_D6, AMPC_LCD_PIN_D7);
    display.print(0, 0, "AmpControl");
    delay(1000);
    display.print(0, 0, "Volume:         ");
    display.print(8, 0, String(encoderValue) + " ");
}

void loop()
{
    uint8_t prevEncoderValue = encoderValue;

    EncoderState encoderState = encoder.checkState();
    if (encoderState == INCREASING && encoderValue < 99)
        encoderValue++;
    if (encoderState == DECREASING && encoderValue > 0)
        encoderValue--;
    
    if (encoderValue != prevEncoderValue)
        display.print(8, 0, String(encoderValue) + " ");

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
