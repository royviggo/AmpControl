#ifndef PGA23XX_H
#define PGA23XX_H

#include "StereoVolume.h"

class Pga23xx : public StereoVolume
{
private:
    const int pinSS;    // SPI: CS
    const int pinSCK;   // SPI: SCLK
    const int pinMOSI;  // SPI: SDI

    const int MIN_VOLUME = 0;
    const int MAX_VOLUME = 192;

    void initialize(int pin);
    int mapVolume(int level, int offset);

public:
    Pga23xx(int pinSS, int pinSCK, int pinMOSI);
    Pga23xx(int pinSS, int pinSCK, int pinMOSI, String name);
    void setVolume(int levelLeft, int levelRight);
};

#endif
