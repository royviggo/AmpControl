#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

class VolumeControl
{
private:
    int minVolume;
    int maxVolume;

public:
    VolumeControl();
    virtual void setVolume(int level) = 0;
    int getMinVolume() const;
    int getMaxVolume() const;
    void setMinVolume(const int level);
    void setMaxVolume(const int level);
};

#endif
