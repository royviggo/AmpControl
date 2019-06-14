#ifndef PGA23XX_H
#define PGA23XX_H

#include "VolumeControl.h"

class Pga23xx : public VolumeControl
{
private:
    const int pinSS;    // SPI: CS
    const int pinSCK;   // SPI: SCLK
    const int pinMOSI;  // SPI: SDI

    const int MIN_VOLUME = 0;
    const int MAX_VOLUME = 192;

public:
    Pga23xx(int pinSS, int pinSCK, int pinMOSI);
    void setVolume(int levelLeft, int levelRight);
    void setVolume(int level);
};

#endif
