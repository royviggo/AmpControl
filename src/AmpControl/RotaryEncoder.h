#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <Arduino.h>

enum EncoderState {
    NONMOVING,
    INCREASING,
    DECREASING,
};

class RotaryEncoder
{
private:
    const uint8_t pinA;
    const uint8_t pinB;
    const bool activePins;

    int prevReadA = 0;
    enum EncoderState state;

public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB, bool activePins);
    EncoderState checkState();
};

#endif
