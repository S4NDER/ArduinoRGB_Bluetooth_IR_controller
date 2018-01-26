#include "../headers/Switch.h"

namespace ArduinoRGB{
    Switch::Switch(){
        on();
    }

    void Switch::on(void){
        switchState = true;
    }

    void Switch::off(void){
        switchState = false;
    }

    bool Switch::getState(void){
        return switchState;
    }
}
