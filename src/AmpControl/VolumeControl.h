#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

#include "StereoVolume.h"

class VolumeControl
{
private:
    const int MIN_VOLUME = 0;
    const int MAX_VOLUME = 255;
    const int VOLUME_CHANGE = 1;

    int numberOfControls;
    int minVolume;
    int maxVolume;
    int volumeChange;

    int volumeLevel;
    int balanceLevel;
    bool muted;

    StereoVolume* volume[6];

    int getRightLevel();
    int getLeftLevel();

    bool useConverter;
    float(*convertNumberFunction)(int);
    float(*convertDbFunction)(int);

public:
    VolumeControl();
    VolumeControl(const int minVolume, const int maxVolume, const int volumeChange);
    VolumeControl(const int minVolume, const int maxVolume, const int volumeChange, float(*convertNumberFunction)(int), float(*convertDbFunction)(int));

    void begin(StereoVolume* volume1);
    void begin(StereoVolume* volume1, StereoVolume* volume2);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3, StereoVolume* volume4);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3, StereoVolume* volume4, StereoVolume* volume5);
    void begin(StereoVolume* volume1, StereoVolume* volume2, StereoVolume* volume3, StereoVolume* volume4, StereoVolume* volume5, StereoVolume* volume6);

    int getMinVolume() const;
    int getMaxVolume() const;
    int getNumberOfControls() const;

    int getVolume();
    void setVolume(int level);
    int setGetVolume(int level);

    float getVolumeNumber();
    float getVolumeDb();

    int getBalance();
    void setBalance(int level);

    void increase();
    void decrease();

    void mute();
    void unmute();
    void flipMute();
    bool isMuted();
};

#endif
