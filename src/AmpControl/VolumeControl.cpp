#include "VolumeControl.h"

VolumeControl::VolumeControl()
{
    numberOfControls = 2;
    minVolume = MIN_VOLUME;
    maxVolume = MAX_VOLUME;
    volumeChange = VOLUME_CHANGE;

    setVolume(0);
    setBalance(0);
}

VolumeControl::VolumeControl(const float minVolume, const float maxVolume, const float volumeChange)
    : numberOfControls(numberOfControls), minVolume(minVolume), maxVolume(maxVolume), volumeChange(volumeChange) {}

void VolumeControl::begin(StereoVolume *volume1)
{
    numberOfControls = 1;
    volume[0] = volume1;
}

void VolumeControl::begin(StereoVolume *volume1, StereoVolume *volume2)
{
    numberOfControls = 2;
    volume[0] = volume1;
    volume[1] = volume2;
}

void VolumeControl::begin(StereoVolume *volume1, StereoVolume *volume2, StereoVolume *volume3)
{
    numberOfControls = 3;
    volume[0] = volume1;
    volume[1] = volume2;
    volume[2] = volume3;
}

void VolumeControl::begin(StereoVolume *volume1, StereoVolume *volume2, StereoVolume *volume3, StereoVolume *volume4)
{
    numberOfControls = 4;
    volume[0] = volume1;
    volume[1] = volume2;
    volume[2] = volume3;
    volume[3] = volume4;
}

void VolumeControl::begin(StereoVolume *volume1, StereoVolume *volume2, StereoVolume *volume3, StereoVolume *volume4, StereoVolume *volume5)
{
    numberOfControls = 5;
    volume[0] = volume1;
    volume[1] = volume2;
    volume[2] = volume3;
    volume[3] = volume4;
    volume[4] = volume5;
}

void VolumeControl::begin(StereoVolume *volume1, StereoVolume *volume2, StereoVolume *volume3, StereoVolume *volume4, StereoVolume *volume5, StereoVolume *volume6)
{
    numberOfControls = 6;
    volume[0] = volume1;
    volume[1] = volume2;
    volume[2] = volume3;
    volume[3] = volume4;
    volume[4] = volume5;
    volume[5] = volume6;
}

float VolumeControl::getMinVolume() const { return minVolume; }
float VolumeControl::getMaxVolume() const { return maxVolume; }
int VolumeControl::getNumberOfControls() const { return numberOfControls; }

float VolumeControl::getVolume() { return volumeLevel; }

void VolumeControl::setVolume(float level)
{
    volumeLevel = level >= getMinVolume() && level <= getMaxVolume()
        ? level
        : level < getMinVolume() ? getMinVolume() : getMaxVolume();

    for (byte i; i < getNumberOfControls(); i++)
        volume[i]->setVolume(getLeftLevel(), getRightLevel());
}

float VolumeControl::setGetVolume(float level)
{
    setVolume(level);
    return getVolume();
}

float VolumeControl::getBalance() { return balanceLevel; }

void VolumeControl::setBalance(float level)
{
    balanceLevel = level >= (0 - getMaxVolume()) && level <= getMaxVolume()
        ? level
        : level < (0 - getMaxVolume()) ? 0 - getMaxVolume() : getMaxVolume();
}

float VolumeControl::getRightLevel()
{
    return getBalance() < 0 
        ? getVolume() + getBalance() > getMinVolume() ? getVolume() + getBalance() : getMinVolume()
        : getVolume();
}

float VolumeControl::getLeftLevel()
{
    return getBalance() > 0 
        ? getVolume() - getBalance() > getMinVolume() ? getVolume() - getBalance() : getMinVolume()
        : getVolume();
}

void VolumeControl::increase()
{
    setVolume(getVolume() + volumeChange);
}

void VolumeControl::decrease()
{
    setVolume(getVolume() - volumeChange);
}
