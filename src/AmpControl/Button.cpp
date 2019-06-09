#include "Button.h"

Button::Button(uint8_t pin, uint8_t mode) : pin(pin), mode(mode)
{
    pinMode(pin, mode);
    state = (mode == INPUT) ? LOW : HIGH;
    // pinMode(pin, INPUT_PULLUP);
    // state = HIGH;
}

int Button::getState() const { return state; }
void Button::setState(int state) { this->state = state; }

bool Button::isPressed() const 
{ 
    return ((mode == INPUT && state == HIGH) || 
            (mode == INPUT_PULLUP && state == LOW));
    // if (getState() == LOW)
    //     return true;
    // return false;
}

void Button::check()
{
    // int prevState = getState();
    setState(digitalRead(pin));

    // if (prevState == HIGH && state == LOW)
    // {
    //     buttonDownMs = millis();
    // }
    // else if (prevState == LOW && state == HIGH)
    // {
    //     if (millis() - buttonDownMs < 50)
    //     {
    //         // ignore this for debounce
    //     }
    //     else if (millis() - buttonDownMs < 250)
    //     {
    //         shortClick();
    //     }
    //     else
    //     {
    //         longClick();
    //     }
    // }
}

