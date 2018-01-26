#pragma once

#include "Defines.h"
#include "LEDController.h"
#include "Color.h"
#include "Effect.h"

namespace ArduinoRGB{

class CommandProcessor {
private:
    LEDController controller;
    Color color;
    Color prevColor;
    Effect effect;

    unsigned long inputCommand;

    unsigned char rgb_red = 0;
    unsigned char rgb_green = 0;
    unsigned char rgb_blue = 0;
    bool rgb_red_done = false;
    bool rgb_green_done = false;
    bool rgb_blue_done = false;

    unsigned char brightnessCounter = 0;
    bool doneBrightUp = true;
    bool doneBrightDown = false;

    unsigned char flashCounter = 0;
    unsigned short int delayTime = 100;

public:
    CommandProcessor (void);
    void processCommand (void);
    void setInputCommand(unsigned long inputCommand);
    void setRGBColor(unsigned char red, unsigned char green, unsigned char blue);
    void setDelay(unsigned short int delayTime);
    void bassFlicker(void);
};
};
