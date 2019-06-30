#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

#include "StereoVolume.h"

class VolumeControl
{
private:
    const float MIN_VOLUME = 0.0;
    const float MAX_VOLUME = 96.0;
    const float VOLUME_CHANGE = 0.5;

    int numberOfControls;
    float minVolume;
    float maxVolume;
    float volumeChange;

    float volumeLevel;
    float balanceLevel;

    StereoVolume* volume[6];

    float getRightLevel();
    float getLeftLevel();

public:
    VolumeControl();
    VolumeControl(const float minVolume, const float maxVolume, const float volumeChange);

    void begin(StereoVolume* volume1);
    void begin(StereoVolume* volume1, StereoVolume* volume2);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3, StereoVolume* volume4);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3, StereoVolume* volume4, StereoVolume* volume5);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3, StereoVolume* volume4, StereoVolume* volume5, StereoVolume* volume6);

    float getMinVolume() const;
    float getMaxVolume() const;
    int getNumberOfControls() const;

    float getVolume();
    void setVolume(float level);
    float setGetVolume(float level);

    float getBalance();
    void setBalance(float level);

    void increase();
    void decrease();
};

#endif
