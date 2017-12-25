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
        inputCommand = 0;
        break;

        case IR_BRIGHT_DOWN:
        effect.bright_down(color);
        inputCommand = 0;
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
        if(!rgb_red_done){
            if(rgb_red == 255){
                rgb_red_done = true;
                rgb_green_done = false;
            } else{
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red+1),(rgb_green),(rgb_blue)),2);
                rgb_red ++;
                rgb_green_done = true;
                rgb_blue_done = true;
            }
        }

        if(!rgb_green_done){
            if(rgb_green == 255){
                rgb_green_done = true;
                rgb_blue_done = false;
            } else{
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green+1),(rgb_blue)),2);
                rgb_green ++;
                rgb_red --;
                rgb_blue_done = true;
            }
        }

        if(!rgb_blue_done){
            if(rgb_blue == 255){
                rgb_blue_done = true;
            } else{
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green),(rgb_blue+1)),2);
                rgb_blue ++;
                rgb_green --;
            }
        }

        if(rgb_red_done & rgb_green_done & rgb_blue_done){
            if(rgb_blue == 0){
                rgb_red_done = false;
            } else {
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green),(rgb_blue-1)),2);
                rgb_blue --;
            }
        }
        color.set_color(rgb_red,rgb_green, rgb_blue);
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
