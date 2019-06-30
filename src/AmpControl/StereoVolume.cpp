#include "StereoVolume.h"

StereoVolume::StereoVolume() { name = DEFAULT_NAME; }
StereoVolume::~StereoVolume() { }

String StereoVolume::getName() { return name; }
void StereoVolume::setName(String name) { this->name = name; }

float StereoVolume::getOffsetLeft() { return offsetLeft; }
float StereoVolume::getOffsetRight() { return offsetRight; }

void StereoVolume::setOffset(float offsetLeft, float offsetRight)
{
    this->offsetLeft = offsetLeft;
    this->offsetRight = offsetRight;
}
