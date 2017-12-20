#include "Color.h"
#include "Arduino.h"

#define COMMON_ANODE

Color::Color (void){
    set_color(255,0,0);
}

Color::Color (float red, float green, float blue){
    set_color(red, green, blue);
}

void Color::set_color (float red, float green, float blue){
    set_red(red);
    set_green(green);
    set_blue(blue);
}

void Color::set_red(float red){
    this->red = red;
}

void Color::set_green(float green){
    this->green = green;
}

void Color::set_blue(float blue){
    this->blue = blue;
}

float Color::get_red(void){
    return red;
}

float Color::get_green(void){
    return green;
}

float Color::get_blue(void){
    return blue;
}
