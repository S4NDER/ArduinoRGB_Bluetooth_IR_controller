#pragma once

#include "Arduino.h"
#include <IRLibDecodeBase.h>
#include <IRLib_P01_NEC.h>
#include <IRLibCombo.h>
#include <IRLibRecvPCI.h>
#include <IRLibRecv.h>

namespace ArduinoRGB{

class IRDecoder {
private:
    IRdecode decoder;
    IRrecv receiver = IRrecv(10);
    unsigned long irCode = 0;
    bool isChanged = true;
    bool beatsEnabled = false;
    unsigned long prevCode = 0;

public:
    IRDecoder (void);
    void init(void);
    void receiveCode(void);
    bool hasChanged(void);
    unsigned long getIRValue(void);

private:
    void startReceiver(void);
    void decodeData(void);
};
};
