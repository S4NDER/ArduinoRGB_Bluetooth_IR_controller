#pragma once

#include "Arduino.h"
#include <SoftwareSerial.h>



class HC06 {
private:
    SoftwareSerial BT = SoftwareSerial(11, 12);                                 //RX, TX

public:
    HC06 (void);
    void init(void);
    String getInput(void);
    //char getData(void);
};
