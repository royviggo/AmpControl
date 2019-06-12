#include "Button.h"

Button::Button(uint8_t pin, bool activePin) : pin(pin), activePin(activePin)
{
    pinMode(pin, activePin ? INPUT : INPUT_PULLUP);
    state = NONCLICK;
}

Button::Button(uint8_t pin, bool activePin, bool useLongClick, int longClickLimitMs)
    : pin(pin), activePin(activePin), useLongClick(useLongClick), longClickLimitMs(longClickLimitMs)
{
    pinMode(pin, activePin ? INPUT : INPUT_PULLUP);
    state = NONCLICK;
}

bool Button::isButtonDown(int pinState) const
{
    return (activePin && pinState == HIGH) || (!activePin && pinState == LOW);
}

ButtonState Button::checkState()
{
    ButtonState prevState = state;
    state = isButtonDown(digitalRead(pin)) 
        ? CLICKING 
        : prevState == CLICKING ? RELEASING : NONCLICK;

    // Start timer if we get a new click
    if (state == CLICKING && prevState == NONCLICK)
        buttonDownMs = millis();

    // TODO: Do we want to continuously register long clicks?
    // if (state == CLICKING && useLongClick && millis() - buttonDownMs > longClickLimitMs)
    //     state = LONG_CLICK;

    // Register button clicks when the button is released
    if (state == RELEASING)
    {
        // Button is released - check how long we clicked it
        if (useLongClick && millis() - buttonDownMs > longClickLimitMs)
            state = LONG_CLICK;
        else if (millis() - buttonDownMs > DEBOUNCE_LIMIT)
            state = NORMAL_CLICK;
    }

    return state;
}
