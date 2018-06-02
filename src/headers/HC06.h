#pragma once

#include "Arduino.h"
#include <SoftwareSerial.h>

namespace ArduinoRGB{

class HC06 {
private:
    SoftwareSerial BT = SoftwareSerial(11, 12);                                 //RX, TX

public:
    HC06 (void);
    void init(void);
    String getInput(void);
};
}
