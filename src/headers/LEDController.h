#pragma once
#include "Color.h"
#include "Switch.h"

#define MIN_SCALE 0
#define MAX_SCALE 255

#define PIN_RED 3
#define PIN_GREEN 5
#define PIN_BLUE 6

namespace ArduinoRGB{

class LEDController {
public:
    Switch powerSwitch;
    LEDController (void);
    void setLED(Color color);
};
};
