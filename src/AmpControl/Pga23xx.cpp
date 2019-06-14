#include "Pga23xx.h"
#include <SPI.h>

Pga23xx::Pga23xx(int pinSS, int pinSCK, int pinMOSI) : pinSS(pinSS), pinSCK(pinSCK), pinMOSI(pinMOSI)
{
    setMinVolume(MIN_VOLUME);
    setMaxVolume(MAX_VOLUME);
    pinMode(pinSS, OUTPUT);
    SPI.begin();
}

void Pga23xx::setVolume(int levelLeft, int levelRight)
{
    digitalWrite(pinSS, LOW);
    SPI.transfer(levelLeft); // right channel
    SPI.transfer(levelRight); // left channel
    digitalWrite(pinSS, HIGH);
}

void Pga23xx::setVolume(int level)
{
    setVolume(level, level);
}
