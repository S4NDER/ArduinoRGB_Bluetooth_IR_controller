#include "HC06.h"
#include "Microphone.h"
#include "IRDecoder.h"
#include "JSONDecoder.h"
#include "CommandProcessor.h"
#include "Color.h"
#include "Effect.h"
#include "LEDController.h"

#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

#define BT_COMMAND 1

CommandProcessor commandProcessor;
JSONDecoder jsonDecoder;
Microphone microphone;
IRDecoder irReceiver;
HC06 hc06;

Thread thIR = Thread();
Thread thBT = Thread();
Thread thProcessInputCommand = Thread();

void setup() {
    Serial.begin(9600);
    irReceiver.init();
    microphone.init();
    hc06.init();

    thIR.setInterval(2);
    thIR.onRun(processIR);

    thBT.setInterval(10);
    thBT.onRun(processBT);

    thProcessInputCommand.setInterval(10);
    thProcessInputCommand.onRun(processInputCommand);
}

void loop() {
    thIR.run();
    thBT.run();
    thProcessInputCommand.run();
}

void processBT(){
    jsonDecoder.decodeString(hc06.getInput());
    if( jsonDecoder.getValueIRCode() > 0 )
      commandProcessor.setInputCommand(jsonDecoder.getValueIRCode());
}

void processIR(){
    irReceiver.receiveCode();
    if(irReceiver.hasChanged())
        commandProcessor.setInputCommand(irReceiver.getIRValue());
}

void processInputCommand(){
    commandProcessor.processCommand();
}
