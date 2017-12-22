#pragma once
#include "Color.h"
#include "LEDController.h"

class Effect {
private:
    LEDController controller;

    float temp_red;
    float temp_green;
    float temp_blue;
    

public:
    Effect (void);

    void set_controller(LEDController &controller);
    void flash (Color color, unsigned short int delaytime);
    void normalize_to_color(Color color_temp, Color color_to_normalize_to, unsigned short int delaytime);
    void cycle_rgb(unsigned short int delaytime);
    void bright_up(Color &color_temp);
    void bright_down(Color &color_temp);
    void cycly_rgb(void);
};
