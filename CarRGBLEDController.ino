#include "HC06.h"
#include "Microphone.h"
#include "IRDecoder.h"
#include "JSONDecoder.h"
#include "CommandProcessor.h"
#include "Color.h"
#include "Effect.h"
#include "LEDController.h"

#define BT_COMMAND 1

CommandProcessor commandProcessor;
JSONDecoder jsonDecoder;
Microphone microphone;
IRDecoder irReceiver;
HC06 hc06;

void setup() {
    Serial.begin(9600);
    irReceiver.init();
    microphone.init();
    hc06.init();
}

void loop() {

    commandProcessor.processCommand(irReceiver.getCode());

}
