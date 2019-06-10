#include "Button.h"

Button::Button(uint8_t pin, uint8_t mode, void(*normalClickFunction)()) : pin(pin), mode(mode), normalClickFunction(normalClickFunction)
{
    pinMode(pin, mode);
    state = (mode == INPUT) ? LOW : HIGH;
}

Button::Button(uint8_t pin, uint8_t mode, void(*normalClickFunction)(), void(*longClickFunction)(), int longClickLimitMs) 
    : pin(pin), mode(mode), normalClickFunction(normalClickFunction), longClickFunction(longClickFunction), longClickLimitMs(longClickLimitMs)
{
    pinMode(pin, mode);
    state = (mode == INPUT) ? LOW : HIGH;
    useLongClick = true;
}

int Button::getState() const { return state; }
void Button::setState(int state) { this->state = state; }
bool Button::isButtonDown() const { return isButtonDown(getState()); }

bool Button::isButtonDown(int s) const
{
    return ((mode == INPUT && s == HIGH) ||
            (mode == INPUT_PULLUP && s == LOW));
}

void Button::check()
{
    bool prevButtonDown = isButtonDown();
    setState(digitalRead(pin));

    // Start timer when we get a new click
    if (isButtonDown() && !prevButtonDown)
        buttonDownMs = millis();

    // TODO: Do we want to continuously register long clicks?
    // if (isButtonDown() && useLongClick && millis() - buttonDownMs > longClickLimitMs)
    //     longClickFunction();

    // Register button clicks when the button is released
    if (!isButtonDown() && prevButtonDown)
    {
        // Button is released - check how long we Clicked it
        if (useLongClick && millis() - buttonDownMs > longClickLimitMs)
            longClickFunction();
        else if (millis() - buttonDownMs > DEBOUNCE_LIMIT)
            normalClickFunction();
    }
}
