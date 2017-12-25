#pragma once
#include "Arduino.h"
#include "Defines.h"
#include <ArduinoJson.h>

#define JSON_BUFFER 320
#define DATA_BUFFER 315

class JSONDecoder {
private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned short int delayTime;
    unsigned long valueIRCode = IR_RED;
    bool beatsEnabled;
    bool isChanged = true;
    String previousCode = "";

public:
    JSONDecoder (void);
    void decodeString(String input);
    unsigned char getValueRed (void);
    unsigned char getValueGreen (void);
    unsigned char getValueBlue (void);
    unsigned short int getValueDelay (void);
    unsigned long getValueIRCode (void);
    bool getBeatEnabled(void);
    bool hasChanged (void);
};
