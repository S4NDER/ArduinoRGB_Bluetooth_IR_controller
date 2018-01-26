#include "../headers/Effect.h"
#include "Arduino.h"

#define E_RED Color(255,0,0)
#define E_GREEN Color(0,255,0)
#define E_BLUE Color(0,0,255)
#define E_OFF Color(0,0,0)

namespace ArduinoRGB{

Effect::Effect(void){
    this->controller = controller;
}

void Effect::setController(LEDController &controller){
    this->controller = controller;
}

void Effect::flash (Color color, unsigned short int delaytime){
    controller.setLED(color);
    delay(delaytime);
    controller.setLED(E_OFF);
    delay(delaytime);
}
void Effect::increaseBrightness(Color &color_temp){
    float temp_red = color_temp.getRed();
    float temp_green = color_temp.getGreen();
    float temp_blue = color_temp.getBlue();

    if(color_temp.getRed()*1.1 <= 255.00){
        temp_red = color_temp.getRed()*1.1;
    }
    if(color_temp.getRed() == 0){
        temp_red = 0;
    }
    if(color_temp.getGreen()*1.1 <= 255){
        temp_green= color_temp.getGreen()*1.1;
    }
    if(color_temp.getGreen() == 0){
        temp_green = 0;
    }
    if(color_temp.getBlue()*1.1 <= 255){
        temp_blue = color_temp.getBlue()*1.1;
    }
    if(color_temp.getBlue() == 0){
        temp_blue = 0;
    }
    color_temp.setColor(temp_red, temp_green, temp_blue);
    controller.setLED(color_temp);
}

void Effect::decreaseBrightness(Color &color_temp){
    float temp_red = color_temp.getRed();
    float temp_green = color_temp.getGreen();
    float temp_blue = color_temp.getBlue();

    if(color_temp.getRed()/1.1 > 5){
        temp_red = color_temp.getRed()/1.1;
    }
    if(color_temp.getRed() == 0){
        temp_red = 0;
    }
    if(color_temp.getGreen()/1.1 > 5){
        temp_green = color_temp.getGreen()/1.1;
    }
    if(color_temp.getGreen() == 0){
        temp_green = 0;
    }
    if(color_temp.getBlue()/1.1 > 5){
        temp_blue = color_temp.getBlue()/1.1;
    }
    if(color_temp.getBlue() == 0){
        temp_blue = 0;
    }
    color_temp.setColor(temp_red, temp_green, temp_blue);
    controller.setLED(color_temp);
}

void Effect::normalizeToColor(Color color_temp, Color color_to_normalize_to, unsigned short int delaytime){
    float temp_red = color_temp.getRed();
    float temp_green = color_temp.getGreen();
    float temp_blue = color_temp.getBlue();

    bool done_red = false;
    bool done_green = false;
    bool done_blue = false;
    while(!(done_red & done_green & done_blue)){
        if(!interrupted){
        if (color_temp.getRed() > color_to_normalize_to.getRed()) {
            temp_red --;
        } else if (color_temp.getRed() < color_to_normalize_to.getRed()) {
            temp_red ++;
        } else{
            done_red = true;
        }

        if (color_temp.getGreen() > color_to_normalize_to.getGreen()) {
            temp_green --;
        } else if (color_temp.getGreen() < color_to_normalize_to.getGreen()) {
            temp_green ++;
        } else{
            done_green = true;
        }


        if (color_temp.getBlue() > color_to_normalize_to.getBlue()) {
            temp_blue --;
        } else if (color_temp.getBlue() < color_to_normalize_to.getBlue()) {
            temp_blue ++;
        } else{
            done_blue = true;
        }

        color_temp.setColor(temp_red, temp_green, temp_blue);
        delay(delaytime);
        controller.setLED(color_temp);
    } else {
        break;
    }
    }

}

void Effect::cycleRGB(unsigned short int delaytime){
    if(!interrupted) normalizeToColor(E_OFF, E_RED,delaytime);
    if(!interrupted) normalizeToColor(E_RED, E_GREEN,delaytime);
    if(!interrupted) normalizeToColor(E_GREEN, E_BLUE,delaytime);
    if(!interrupted) normalizeToColor(E_BLUE, E_OFF,delaytime);
}

void Effect::cycleRGB(void){
    cycleRGB(5);
}

void Effect::interrupt(void){
    interrupted = true;
}
};
