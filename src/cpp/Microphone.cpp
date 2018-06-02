#include "../headers/Microphone.h"
#include "Arduino.h"
//#include <Filters.h>

#define INPUT_PIN 0

namespace ArduinoRGB{

Microphone::Microphone (void){
    init();
}

void Microphone::init(void){
    Serial.begin(9600);
}

float Microphone::getMicLevel(void){
    //FilterOnePole lowPassFilter (LOWPASS, filterFrequency);
    return analogRead(INPUT_PIN);
}

bool Microphone::hasBass(void){
    float miclevel = getMicLevel();
    if(miclevel >= bassThreshold){
        Serial.println(miclevel);
        return true;
    }
    return false;
}

float Microphone::getFilterFrequency(void){
    return filterFrequency;
}

void Microphone::setFilterFrequency(float filterFrequency){
    this->filterFrequency = filterFrequency;
}

void Microphone::setBassThreshold(unsigned short int bassThreshold){
    this->bassThreshold = bassThreshold;
}
};
