#include <Arduino.h>
#include "LcdDisplay.h"
#include "Button.h"
#include "RotaryEncoder.h"
#include "VolumeControl.h"
#include "Pga23xx.h"

// Setup for the LCD display
const int AMPC_LCD_COLS = 16;
const int AMPC_LCD_ROWS = 2;
const int AMPC_LCD_CHARSIZE = 0;

// Arduino pins for the LCD display
const int AMPC_LCD_PIN_RS = PIN_A5;
const int AMPC_LCD_PIN_EN = PIN_A4;
const int AMPC_LCD_PIN_D4 = PIN_A3;
const int AMPC_LCD_PIN_D5 = PIN_A2;
const int AMPC_LCD_PIN_D6 = PIN_A1;
const int AMPC_LCD_PIN_D7 = PIN_A0;

// Button pins
const int AMPC_BUTTON_LEFT = 2;
const int AMPC_BUTTON_RIGHT = 3;
const int AMPC_BUTTON_SELECT = 4;
const int AMPC_BUTTON_SELECT_LONG = true;
const int AMPC_BUTTON_ACTIVE_PINS = false;

// Rotary encoder
const int AMPC_ENCODER_PINA = PIN5;
const int AMPC_ENCODER_PINB = PIN6;
const int AMPC_ENCODER_ACTIVE_PINS = false;

// Volume control
const int AMPC_VOLUME_PIN_SS = PIN_SPI_SS;
const int AMPC_VOLUME_PIN_SCK = PIN_SPI_SCK;
const int AMPC_VOLUME_PIN_MOSI = PIN_SPI_MOSI;
const int AMPC_VOLUME_MIN_VOLUME = 0;
const int AMPC_VOLUME_MAX_VOLUME = 192;
const int AMPC_VOLUME_CHANGE_BY = 1;
const int AMPC_BUTTON_MUTE = PIN7;

// Global variables
LcdDisplay display = LcdDisplay(AMPC_LCD_COLS, AMPC_LCD_ROWS, AMPC_LCD_CHARSIZE);

Button leftBtn = Button(AMPC_BUTTON_LEFT, AMPC_BUTTON_ACTIVE_PINS);
Button rightBtn = Button(AMPC_BUTTON_RIGHT, AMPC_BUTTON_ACTIVE_PINS);
Button selectBtn = Button(AMPC_BUTTON_SELECT, AMPC_BUTTON_ACTIVE_PINS, AMPC_BUTTON_SELECT_LONG);

Button muteBtn = Button(AMPC_BUTTON_MUTE, AMPC_BUTTON_ACTIVE_PINS);
RotaryEncoder encoder = RotaryEncoder(AMPC_ENCODER_PINA, AMPC_ENCODER_PINB, AMPC_ENCODER_ACTIVE_PINS);

VolumeControl volume = VolumeControl(AMPC_VOLUME_MIN_VOLUME, AMPC_VOLUME_MAX_VOLUME, AMPC_VOLUME_CHANGE_BY, &convertVolumeToNumber);
Pga23xx pgaVolume = Pga23xx(AMPC_VOLUME_PIN_SS, AMPC_VOLUME_PIN_SCK, AMPC_VOLUME_PIN_MOSI, "Bass");

float prevVolumeLevel = 0;
int prevMute;

void setup()
{
    volume.begin(&pgaVolume);
    volume.setBalance(0);

    display.begin(AMPC_LCD_PIN_RS, AMPC_LCD_PIN_EN, AMPC_LCD_PIN_D4, AMPC_LCD_PIN_D5, AMPC_LCD_PIN_D6, AMPC_LCD_PIN_D7);
    display.print(0, 0, "AmpControl");
    delay(1000);
    display.print(0, 0, "Volume:         ");
    display.print(8, 0, String(volume.getVolume()) + " ");

    Serial.begin(115200);
    Serial.println("Setup Ok");
    Serial.print("Initial Volume: ");
    Serial.println(volume.getVolumeView());
}

void loop()
{
    prevVolumeLevel = volume.getVolumeView();
    prevMute = volume.isMuted();

    EncoderState encoderState = encoder.checkState();
    if (encoderState == INCREASING)
        volume.increase();
    if (encoderState == DECREASING)
        volume.decrease();
    
    if (muteBtn.checkState() == NORMAL_CLICK)
        volume.flipMute();

    if (volume.getVolumeView() != prevVolumeLevel || volume.isMuted() != prevMute)
    {
        display.print(8, 0, String(volume.getVolume()) + " ");
        Serial.print("Volume: ");
        Serial.print(volume.getVolumeView());
        Serial.print(" - Balance: ");
        Serial.print(volume.getBalance());
        Serial.println(volume.isMuted() ? "  --Muted--" : "");
    }
}

float convertVolumeToNumber(int level)
{
    return (float)level / 2.0;
}

float convertVolumeToDb(int level)
{
    return (float)(level - 192.0) / 2.0;
}
