#ifndef STEREOVOLUME_H
#define STEREOVOLUME_H

#include <Arduino.h>

class StereoVolume
{
private:
    const String DEFAULT_NAME = "Stereo";
    String name;
    float offsetLeft;
    float offsetRight;

protected:
    void setName(String name);
    float getOffsetLeft();
    float getOffsetRight();

public:
    StereoVolume();
    virtual ~StereoVolume();
    virtual void setVolume(float levelLeft, float levelRight) = 0;
    void setOffset(float offsetLeft, float offsetRight);
    String getName();
};

#endif
