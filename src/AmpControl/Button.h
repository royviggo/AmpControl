#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
    const uint8_t pin;
    const uint8_t mode;
    int state;
    unsigned long buttonDownMs;

// protected:
//     virtual void shortClick() = 0;
//     virtual void longClick() = 0;

public:
    Button(uint8_t pin, uint8_t mode);
    int getState() const;
    void setState(int state);
    bool isPressed() const;
    void check();
};

#endif
