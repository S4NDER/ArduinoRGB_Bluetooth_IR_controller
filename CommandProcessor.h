#pragma once

#include "Defines.h"
#include "LEDController.h"
#include "Color.h"
#include "Effect.h"

class CommandProcessor {
private:
    LEDController controller;
    Color color;
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

public:
    CommandProcessor (void);
    void processCommand (void);
    void setInputCommand(unsigned long inputCommand);
};
