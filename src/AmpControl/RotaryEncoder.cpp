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

    // Catch movement on falling edge
    if (!readA && prevReadA)
        state = readB ? INCREASING : DECREASING;
    else
        state = NONMOVING;

    // Hold the previous read value for pin A
    prevReadA = readA;

    return state;
}
