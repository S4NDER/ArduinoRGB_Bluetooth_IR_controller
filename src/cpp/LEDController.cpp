#include "../headers/LEDController.h"
#include "Arduino.h"

#define COMMON_ANODE

namespace ArduinoRGB{

LEDController::LEDController (void){
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);

}

void LEDController::setLED(Color color){
    if(powerSwitch.getState()){
        #ifdef COMMON_ANODE
        //map(...) is used for PWM because otherwise off = x < 128 and on = x > 128
        float red = MAX_SCALE    - map(color.getRed(), MIN_SCALE, MAX_SCALE, MIN_SCALE, MAX_SCALE);
        float green = MAX_SCALE  - map(color.getGreen(), MIN_SCALE, MAX_SCALE, MIN_SCALE, MAX_SCALE);
        float blue = MAX_SCALE   - map(color.getBlue(), MIN_SCALE, MAX_SCALE, MIN_SCALE, MAX_SCALE);
        #endif
        analogWrite(PIN_RED, red);
        analogWrite(PIN_GREEN, green);
        analogWrite(PIN_BLUE, blue);
    } else{
        analogWrite(PIN_RED, MAX_SCALE);
        analogWrite(PIN_GREEN, MAX_SCALE);
        analogWrite(PIN_BLUE, MAX_SCALE);
    }
}
};
