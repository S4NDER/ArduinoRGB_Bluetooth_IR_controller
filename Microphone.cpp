#include "Microphone.h"
#include "Arduino.h"
#include <Filters.h>

#define INPUT_PIN 0
#define BASS_THRESHOLD 272

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

float Microphone::getBassLevel(void){
    if(getMicLevel() > BASS_THRESHOLD){
        return getMicLevel();
    }
    return 0;
}

float Microphone::getFilterFrequency(void){
    return filterFrequency;
}

void Microphone::setFilterFrequency(float filterFrequency){
    this->filterFrequency = filterFrequency;
}
