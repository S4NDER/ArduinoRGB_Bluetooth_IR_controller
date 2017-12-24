#include "CommandProcessor.h"

CommandProcessor::CommandProcessor (void){

}

void CommandProcessor::processCommand (unsigned long command){
    switch (command) {
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
    }
    controller.set_led(color);

}
