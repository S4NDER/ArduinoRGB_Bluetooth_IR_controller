#include "LEDController.h"
#include "Arduino.h"

#define COMMON_ANODE

LEDController::LEDController (void){
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
}

void LEDController::set_led(Color color){
    #ifdef COMMON_ANODE
    //map(...) is used for PWM because otherwise off = x < 128 and on = x > 128
        unsigned char red = MAX_SCALE    - map(color.get_red(), MIN_SCALE, MAX_SCALE, MIN_SCALE, MAX_SCALE);
        unsigned char green = MAX_SCALE  - map(color.get_green(), MIN_SCALE, MAX_SCALE, MIN_SCALE, MAX_SCALE);
        unsigned char blue = MAX_SCALE   - map(color.get_blue(), MIN_SCALE, MAX_SCALE, MIN_SCALE, MAX_SCALE);
    #endif

    analogWrite(PIN_RED, red);
    analogWrite(PIN_GREEN, green);
    analogWrite(PIN_BLUE, blue);
}
