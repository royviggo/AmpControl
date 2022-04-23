#ifndef SETTINGSSTORE_H
#define SETTINGSSTORE_H

#include <Arduino.h>
#include <EEPROM.h>

struct Settings
{
    char name[10];
    int volumeLevel;
    int balanceLevel;
    int muted;
    int volumeOffsets[10];
    int inputOffsets[10];
    char inputNames[10][10];
};

class SettingsStore
{
private:
    static const int READ_OFFSET = 0;
    static const int READ_LENGTH = 1;

    int settingsOffset;
    int settingsLength;

    Settings defaultSettings;

    void readOffsetAndLength();

public:
    SettingsStore();
    Settings getSettings();
    void saveSettings(Settings settings);
};

#endif
