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

public:
    CommandProcessor (void);
    void processCommand (void);
    void setInputCommand(unsigned long inputCommand);
};
