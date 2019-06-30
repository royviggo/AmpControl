#include "Pga23xx.h"
#include <SPI.h>

Pga23xx::Pga23xx(int pinSS, int pinSCK, int pinMOSI) : pinSS(pinSS), pinSCK(pinSCK), pinMOSI(pinMOSI)
{
    initialize(pinSS);
}

Pga23xx::Pga23xx(int pinSS, int pinSCK, int pinMOSI, String name) : pinSS(pinSS), pinSCK(pinSCK), pinMOSI(pinMOSI)
{
    setName(name);
    initialize(pinSS);
}

void Pga23xx::setVolume(float levelLeft, float levelRight)
{
    digitalWrite(pinSS, LOW);
    SPI.transfer(mapVolume(levelLeft, getOffsetLeft())); // right channel
    SPI.transfer(mapVolume(levelRight, getOffsetRight())); // left channel
    digitalWrite(pinSS, HIGH);
}

int Pga23xx::mapVolume(float level, float offset)
{
    int mappedLevel = int(round((level * 2) + offset));

    if (mappedLevel < MIN_VOLUME)
        return MIN_VOLUME;
    if (mappedLevel > MAX_VOLUME)
        return MAX_VOLUME;

    return mappedLevel;
}

void Pga23xx::initialize(int pin)
{
    setOffset(0, 0);
    pinMode(pinSS, OUTPUT);
    SPI.begin();
}
