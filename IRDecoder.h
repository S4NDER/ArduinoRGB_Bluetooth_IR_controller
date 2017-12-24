#pragma once

#include "Arduino.h"
#include <IRLibDecodeBase.h>
#include <IRLib_P01_NEC.h>
#include <IRLibCombo.h>
#include <IRLibRecvPCI.h>

class IRDecoder {
private:
    IRdecode decoder;
    IRrecvPCI receiver = IRrecvPCI(2);

public:
    IRDecoder (void);
    void init(void);
    unsigned long getCode(void);

private:
    void startReceiver(void);
    void decodeData(void);
    bool hasReceivedData(void);
};
