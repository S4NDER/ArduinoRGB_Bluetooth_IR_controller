#include "Color.h"
#include "Arduino.h"

#define COMMON_ANODE

Color::Color (void){
    set_color(255,0,0);
}

Color::Color (unsigned char red, unsigned char green, unsigned char blue){
    set_color(red, green, blue);
}

void Color::set_color (unsigned char red, unsigned char green, unsigned char blue){
    set_red(red);
    set_green(green);
    set_blue(blue);
}

void Color::set_red(unsigned char red){
    this->red = red;
}

void Color::set_green(unsigned char green){
    this->green = green;
}

void Color::set_blue(unsigned char blue){
    this->blue = blue;
}

unsigned char Color::get_red(void){
    return red;
}

unsigned char Color::get_green(void){
    return green;
}

unsigned char Color::get_blue(void){
    return blue;
}
