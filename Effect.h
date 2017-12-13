#pragma once
#include "Color.h"
#include "LEDController.h"

class Effect {
private:
    LEDController controller;

public:
    Effect (void);

    void flash (Color color, unsigned short int delaytime);
    void normalize_to_color(Color color_temp, Color color_to_normalize_to, unsigned short int delaytime);
    void cycle_rgb(unsigned short int delaytime);
    void cycly_rgb(void);
};
