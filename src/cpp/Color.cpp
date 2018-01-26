#include "../headers/Color.h"

namespace ArduinoRGB{

Color::Color (void){
    setColor(255,0,0);
}

Color::Color (float red, float green, float blue){
    setColor(red, green, blue);
}

void Color::setColor (float red, float green, float blue){
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

void Color::setRed(float red){
    this->red = red;
}

void Color::setGreen(float green){
    this->green = green;
}

void Color::setBlue(float blue){
    this->blue = blue;
}

float Color::getRed(void){
    return red;
}

float Color::getGreen(void){
    return green;
}

float Color::getBlue(void){
    return blue;
}
};
