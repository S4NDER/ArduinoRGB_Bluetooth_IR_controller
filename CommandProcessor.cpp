#include "CommandProcessor.h"
#include "Arduino.h"

CommandProcessor::CommandProcessor (void){
    controller.set_led(color);
    effect.set_controller(controller);
}

void CommandProcessor::setInputCommand(unsigned long inputCommand){
    this->inputCommand = inputCommand;
    Serial.println(inputCommand);  
}

void CommandProcessor::processCommand (void){
    switch (inputCommand) {
        case IR_WHITE:
        color.WHITE;
        break;

        case IR_RED:
        color.RED;
        break;

        case IR_GREEN:
        color.GREEN;
        break;

        case IR_BLUE:
        color.BLUE;
        break;

        case IR_ORANGE:
        color.ORANGE;
        break;

        case IR_DARK_YELLOW:
        color.DARK_YELLOW;
        break;

        case IR_YELLOW:
        color.YELLOW;
        break;

        case IR_STRAW_YELLOW:
        color.STRAW_YELLOW;
        break;

        case IR_PEA_GREEN:
        color.PEA_GREEN;
        break;

        case IR_CYAN:
        color.CYAN;
        break;

        case IR_LIGHT_BLUE:
        color.LIGHT_BLUE;
        break;

        case IR_SKY_BLUE:
        color.SKY_BLUE;
        break;

        case IR_DARK_BLUE:
        color.DARK_BLUE;
        break;

        case IR_DARK_PINK:
        color.DARK_PINK;
        break;

        case IR_PINK:
        color.PINK;
        break;

        case IR_PURPLE :
        color.PURPLE;
        break;

        case IR_BRIGHT_UP :
        effect.bright_up(color);
        break;

        case IR_BRIGHT_DOWN:
        effect.bright_down(color);
        break;

        case IR_OFF:
        controller.turn_off();
        controller.set_led(color);
        break;

        case IR_ON:
        controller.turn_on();
        controller.set_led(color);
        break;

        case IR_STROBE:
        effect.flash(color, 200);
        break;

        case IR_FADE:

        break;

        case IR_SMOOTH:
        unsigned char i = 0;
        for(i = 0; i < 35; i++){
            effect.bright_down(color);
            delay(100);
        }
        for(i = 35; i > 0 ; i--){
            effect.bright_up(color);
            delay(100);
        }
        break;
    }
    controller.set_led(color);

}
