#pragma once

#include "Defines.h"
#include "LEDController.h"
#include "Color.h"
#include "Effect.h"

class CommandProcessor {
private:
    LEDController controller;
    Color color;

public:
    CommandProcessor (void);
    void processCommand (unsigned long command);
};
