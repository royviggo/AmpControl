#include "VolumeControl.h"

VolumeControl::VolumeControl() {}
int VolumeControl::getMinVolume() const { return minVolume; }
int VolumeControl::getMaxVolume() const { return maxVolume; }
void VolumeControl::setMinVolume(const int level) { minVolume = level; }
void VolumeControl::setMaxVolume(const int level) { maxVolume = level; }
