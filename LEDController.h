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
    void set_led(Color color);
    void turn_on(void);
    void turn_off(void);
    
private:
  bool turnedOn = true;
};
