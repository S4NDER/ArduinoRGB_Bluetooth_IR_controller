#include "../headers/CommandProcessor.h"
#include "Arduino.h"

namespace ArduinoRGB{
CommandProcessor::CommandProcessor (void){
    controller.setLED(color);
    effect.setController(controller);
}

void CommandProcessor::setInputCommand(unsigned long inputCommand){
    this->inputCommand = inputCommand;
}

void CommandProcessor::setRGBColor(unsigned char red, unsigned char green, unsigned char blue){
    color.setColor(red, green, blue);
}

void CommandProcessor::setDelay(unsigned short int delayTime){
    this->delayTime = delayTime;
}

void CommandProcessor::bassFlicker(void){
    if (controller.powerSwitch.getState()) {
        effect.flash(color, 25);
    }
}
void CommandProcessor::processCommand (void){
    if ((controller.powerSwitch.getState()) || (inputCommand == IR_ON)) {
        switch (inputCommand) {
            case IR_WHITE: color.WHITE; break;
            case IR_RED: color.RED; break;
            case IR_GREEN: color.GREEN; break;
            case IR_BLUE: color.BLUE; break;
            case IR_ORANGE: color.ORANGE; break;
            case IR_DARK_YELLOW: color.DARK_YELLOW; break;
            case IR_YELLOW: color.YELLOW; break;
            case IR_STRAW_YELLOW: color.STRAW_YELLOW; break;
            case IR_PEA_GREEN: color.PEA_GREEN; break;
            case IR_CYAN: color.CYAN; break;
            case IR_LIGHT_BLUE: color.LIGHT_BLUE; break;
            case IR_SKY_BLUE: color.SKY_BLUE; break;
            case IR_DARK_BLUE: color.DARK_BLUE; break;
            case IR_DARK_PINK: color.DARK_PINK; break;
            case IR_PINK: color.PINK; break;
            case IR_PURPLE: color.PURPLE; break;
        }
        effect.normalizeToColor(prevColor, color, 1);


        switch (inputCommand){
            case IR_BRIGHT_UP: effect.increaseBrightness(color); inputCommand = 0; break;
            case IR_BRIGHT_DOWN: effect.decreaseBrightness(color); inputCommand = 0; break;
            case IR_OFF: controller.powerSwitch.OFF; controller.setLED(color); break;
            case IR_ON: controller.powerSwitch.ON; controller.setLED(color); break;
            case IR_STROBE: effect.flash(color, delayTime*1.5); break;
            case IR_FLASH:
            switch (flashCounter) {
                case 0: color.WHITE; break;
                case 1: color.RED; break;
                case 2: color.GREEN; break;
                case 3: color.BLUE; break;
                case 4: color.ORANGE; break;
                case 5: color.DARK_YELLOW; break;
                case 6: color.YELLOW; break;
                case 7: color.STRAW_YELLOW; break;
                case 8: color.PEA_GREEN; break;
                case 9: color.CYAN; break;
                case 10: color.LIGHT_BLUE; break;
                case 11: color.SKY_BLUE; break;
                case 12: color.DARK_BLUE; break;
                case 13: color.DARK_PINK; break;
                case 14: color.PINK; break;
                case 15: color.PURPLE; break;
            }
            if(flashCounter < 15){
                flashCounter ++;
            } else{
                flashCounter = 0;
            }
            delay(delayTime*2);
            break;

            case IR_FADE:
            if(!rgb_red_done){
                if(rgb_red == 255){
                    rgb_red_done = true;
                    rgb_green_done = false;
                } else{
                    effect.normalizeToColor(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red+1),(rgb_green),(rgb_blue)),2);
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
                    effect.normalizeToColor(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green+1),(rgb_blue)),2);
                    rgb_green ++;
                    rgb_red --;
                    rgb_blue_done = true;
                }
            }

            if(!rgb_blue_done){
                if(rgb_blue == 255){
                    rgb_blue_done = true;
                } else{
                    effect.normalizeToColor(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green),(rgb_blue+1)),2);
                    rgb_blue ++;
                    rgb_green --;
                }
            }

            if(rgb_red_done & rgb_green_done & rgb_blue_done){
                if(rgb_blue == 0){
                    rgb_red_done = false;
                } else {
                    effect.normalizeToColor(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green),(rgb_blue-1)),2);
                    rgb_blue --;
                }
            }
            color.setColor(rgb_red,rgb_green, rgb_blue);
            delay(delayTime);
            break;

            case IR_SMOOTH:
            if(!doneBrightDown){
                if(brightnessCounter >= 35){
                    doneBrightDown = true;
                    doneBrightUp = false;
                } else{
                    brightnessCounter ++;
                    effect.decreaseBrightness(color);
                    delay(delayTime);
                }
            }
            if(!doneBrightUp){
                if(brightnessCounter <= 0){
                    doneBrightDown = false;
                    doneBrightUp = true;
                } else{
                    brightnessCounter --;
                    effect.increaseBrightness(color);
                    delay(delayTime);
                }
            }
            break;
        }
        if(inputCommand != IR_SMOOTH){
            brightnessCounter = 0;
            doneBrightUp = true;
            doneBrightDown = false;
        }
        if(inputCommand != IR_FLASH){
            flashCounter = 0;
        }
        controller.setLED(color);
        prevColor = color;
    }
}
};
