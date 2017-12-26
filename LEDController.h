#pragma once
#include "Color.h"

#define MIN_SCALE 0
#define MAX_SCALE 255

#define PIN_RED 3
#define PIN_GREEN 5
#define PIN_BLUE 6

class LEDController {
public:
    LEDController (void);
    void setLED(Color color);
    void turnOn(void);
    void turnOff(void);
    bool getPowerState(void);

private:
  bool turnedOn = true;
};
