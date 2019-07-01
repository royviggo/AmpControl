#ifndef STEREOVOLUME_H
#define STEREOVOLUME_H

#include <Arduino.h>

class StereoVolume
{
private:
    const String DEFAULT_NAME = "Stereo";
    String name;
    int offsetLeft;
    int offsetRight;

protected:
    void setName(String name);
    int getOffsetLeft();
    int getOffsetRight();

public:
    StereoVolume();
    virtual ~StereoVolume();
    virtual void setVolume(int levelLeft, int levelRight) = 0;
    void setOffset(int offsetLeft, int offsetRight);
    String getName();
};

#endif
