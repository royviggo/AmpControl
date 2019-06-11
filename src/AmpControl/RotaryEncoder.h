#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <Arduino.h>

enum EncoderState {
    NONE,
    INCREASING,
    DECREASING,
};

class RotaryEncoder
{
private:
    const uint8_t pinA;
    const uint8_t pinB;
    const bool activePins;
    enum EncoderState state;

public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB, bool activePins);
    EncoderState checkState();
};

#endif
