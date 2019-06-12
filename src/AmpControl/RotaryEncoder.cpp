#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, bool activePins) : pinA(pinA), pinB(pinB), activePins(activePins)
{
    // Set input pins
    pinMode(pinA, activePins ? INPUT : INPUT_PULLUP);
    pinMode(pinB, activePins ? INPUT : INPUT_PULLUP);
}

EncoderState RotaryEncoder::checkState()
{
    int readA = digitalRead(pinA);
    int readB = digitalRead(pinB);

    if (readA)
        state = readB ? INCREASING : DECREASING;
    else if (readB)
        state = DECREASING;
    else
        state = NONMOVING;

    return state;
}
