#include "VolumeControl.h"

VolumeControl::VolumeControl()
{
    numberOfControls = 2;
    minVolume = MIN_VOLUME;
    maxVolume = MAX_VOLUME;
    volumeChange = VOLUME_CHANGE;

    muted = false;
    setVolume(0);
    setBalance(0);
}

VolumeControl::VolumeControl(const int minVolume, const int maxVolume, const int volumeChange)
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

int VolumeControl::getMinVolume() const { return minVolume; }
int VolumeControl::getMaxVolume() const { return maxVolume; }
int VolumeControl::getNumberOfControls() const { return numberOfControls; }

int VolumeControl::getVolume() { return volumeLevel; }

void VolumeControl::setVolume(int level)
{
    volumeLevel = level >= getMinVolume() && level <= getMaxVolume()
        ? level
        : level < getMinVolume() ? getMinVolume() : getMaxVolume();

    for (byte i; i < getNumberOfControls(); i++)
        volume[i]->setVolume(getLeftLevel(), getRightLevel());
}

int VolumeControl::setGetVolume(int level)
{
    setVolume(level);
    return getVolume();
}

int VolumeControl::getBalance() { return balanceLevel; }

void VolumeControl::setBalance(int level)
{
    balanceLevel = level >= (0 - getMaxVolume()) && level <= getMaxVolume()
        ? level
        : level < (0 - getMaxVolume()) ? 0 - getMaxVolume() : getMaxVolume();
}

int VolumeControl::getRightLevel()
{
    return getBalance() < 0 
        ? getVolume() + getBalance() > getMinVolume() ? getVolume() + getBalance() : getMinVolume()
        : getVolume();
}

int VolumeControl::getLeftLevel()
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

void VolumeControl::mute()
{
    muted = true;
    for (byte i; i < getNumberOfControls(); i++)
        volume[i]->mute();
}

void VolumeControl::unmute()
{
    muted = false;
    setVolume(getVolume());
}

void VolumeControl::flipMute() { isMuted() ? unmute() : mute(); }
bool VolumeControl::isMuted() { return muted; }
