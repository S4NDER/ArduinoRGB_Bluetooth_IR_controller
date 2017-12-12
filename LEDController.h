#pragma once
#include "Color.h"

class LEDController {
private:
    unsigned char pin_red = 3;
    unsigned char pin_green = 5;
    unsigned char pin_blue = 6;

    Color color;

public:
    LEDController (void);
    void set_led(Color color);
};
