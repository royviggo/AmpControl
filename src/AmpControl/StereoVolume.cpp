#include "StereoVolume.h"

StereoVolume::StereoVolume() { name = DEFAULT_NAME; }
StereoVolume::~StereoVolume() { }

String StereoVolume::getName() { return name; }
void StereoVolume::setName(String name) { this->name = name; }

int StereoVolume::getOffsetLeft() { return offsetLeft; }
int StereoVolume::getOffsetRight() { return offsetRight; }

void StereoVolume::setOffset(int offsetLeft, int offsetRight)
{
    this->offsetLeft = offsetLeft;
    this->offsetRight = offsetRight;
}
