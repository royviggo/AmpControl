#include "SettingsStore.h"

SettingsStore::defaultSettings = {
    "AmpControl",
    0,
    0,
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { "Line 1", "Line 2", "Line 3", "Line 4", "Line 5", "Line 6", "Line 7", "Line 8", "Line 9", "Line 10" },
};

SettingsStore::SettingsStore()
{
    SettingsStore::readOffsetAndLength();
}

void SettingsStore::readOffsetAndLength()
{
    EEPROM.get(READ_OFFSET, settingsOffset);
    EEPROM.get(READ_LENGTH, settingsLength);
}

Settings SettingsStore::getSettings()
{
    Settings settings;
    EEPROM.get(settingsOffset, settings);

    if (setting.name == "")
        settings = defaultSettings;

    return settings;
}

void SettingsStore::saveSettings(Settings settings)
{
    EEPROM.put(settingsOffset, settings);
}
