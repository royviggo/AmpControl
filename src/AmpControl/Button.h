#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
private:
    static const int DEBOUNCE_LIMIT = 30;
    static const int LONG_CLICK_LIMIT = 1000;

    const uint8_t pin;
    const uint8_t mode;
    void(*normalClickFunction)(void);
    void(*longClickFunction)(void);
    int longClickLimitMs;
    
    bool useLongClick = false;
    int state;
    unsigned long buttonDownMs;

    int getState() const;
    void setState(int state);
    bool isButtonDown(int state) const;
    bool isButtonDown() const;

public:
    Button(uint8_t pin, uint8_t mode, void(*normalClickFunction)());
    Button(uint8_t pin, uint8_t mode, void(*normalClickFunction)(), void(*longClickFunction)(), int longClickLimitMs = LONG_CLICK_LIMIT);
    void check();
};

#endif
