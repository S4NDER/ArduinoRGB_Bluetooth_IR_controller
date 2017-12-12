#include "LEDController.h"
#include "Arduino.h"

#define COMMON_ANODE

LEDController::LEDController (void){
    pinMode(pin_red, OUTPUT);
    pinMode(pin_green, OUTPUT);
    pinMode(pin_green, OUTPUT);
}

void LEDController::set_led(Color color){
    #ifdef COMMON_ANODE
        unsigned char red = 255 -  map(color.get_red(), 0, 255, 0, 255);
        unsigned char green = 255 -  map(color.get_green(), 0, 255, 0, 255);
        unsigned char blue = 255 - map(color.get_blue(), 0, 255, 0, 255);
    #endif

    analogWrite(pin_red, red);
    analogWrite(pin_green, green);
    analogWrite(pin_blue, blue);

        Serial.print("RGB(");
        Serial.print(color.get_red());
        Serial.print(", ");
        Serial.print(color.get_green());
        Serial.print(", ");
        Serial.print(color.get_blue());
        Serial.print(")\r\n");

}
