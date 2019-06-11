#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

enum ButtonState {
    NONE,
    CLICKING,
    RELEASING,
    NORMAL_CLICK,
    LONG_CLICK,
};

class Button
{
private:
    static const int DEBOUNCE_LIMIT = 50;
    static const int LONG_CLICK_LIMIT = 1000;

    const uint8_t pin;
    const bool activePin;
    bool useLongClick = false;
    int longClickLimitMs;
    
    enum ButtonState state;
    unsigned long buttonDownMs;

    bool isButtonDown(int pinState) const;

public:
    Button(uint8_t pin, bool active);
    Button(uint8_t pin, bool active, bool useLongClick, int longClickLimitMs = LONG_CLICK_LIMIT);
    ButtonState checkState();
};

#endif
