#include "Microphone.h"
#include "Arduino.h"
#include <Filters.h>

#define INPUT_PIN 0

Microphone::Microphone (void){
    init();
}

void Microphone::init(void){
    Serial.begin(9600);
}

float Microphone::getMicLevel(void){
    FilterOnePole lowPassFilter (LOWPASS, filterFrequency);
    return lowPassFilter.input(analogRead(INPUT_PIN));
}

bool Microphone::hasBass(void){
    Serial.println(getMicLevel());
    if(getMicLevel() > bassThreshold){
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
