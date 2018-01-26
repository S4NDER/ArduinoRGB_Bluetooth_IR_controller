#pragma once
#include "Color.h"
#include "LEDController.h"

class Effect {
private:
    LEDController controller;

public:
    Effect (void);

    void setController(LEDController &controller);
    void flash (Color color, unsigned short int delaytime);
    void normalizeToColor(Color color_temp, Color color_to_normalize_to, unsigned short int delaytime);
    void cycleRGB(unsigned short int delaytime);
    void increaseBrightness(Color &color_temp);
    void decreaseBrightness(Color &color_temp);
    void cycleRGB(void);
};
