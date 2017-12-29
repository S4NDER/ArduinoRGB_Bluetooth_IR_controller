#include "HC06.h"
#include "Microphone.h"
#include "IRDecoder.h"
#include "JSONDecoder.h"
#include "CommandProcessor.h"
#include "Defines.h"

#include <Thread.h>

CommandProcessor commandProcessor;
JSONDecoder jsonDecoder;
Microphone microphone;
IRDecoder irReceiver;
HC06 hc06;

Thread thIR = Thread();
Thread thBT = Thread();
Thread thMic = Thread();
Thread thProcessInputCommand = Thread();

void setup() {
    Serial.begin(9600);
    irReceiver.init();
    microphone.init();
    microphone.setBassThreshold(265);
    microphone.setFilterFrequency(250);
    hc06.init();

    thIR.setInterval(2);
    thIR.onRun(processIR);

    thBT.setInterval(10);
    thBT.onRun(processBT);

    thMic.setInterval(5);
    thMic.onRun(processMic);

    thProcessInputCommand.setInterval(10);
    thProcessInputCommand.onRun(processInputCommand);
}

void loop() {
    thIR.run();
    thBT.run();
    thMic.run();
    thProcessInputCommand.run();
}

void processBT(){
    jsonDecoder.decodeString(hc06.getInput());
    if (jsonDecoder.hasChanged()) {
        if( jsonDecoder.getValueIRCode() > 0 ){
          commandProcessor.setInputCommand(jsonDecoder.getValueIRCode());
        }
    }
    if (jsonDecoder.hasRGBInput()) {
        commandProcessor.setInputCommand(BT_COMMAND);
        commandProcessor.setRGBColor(jsonDecoder.getValueRed(), jsonDecoder.getValueGreen(), jsonDecoder.getValueBlue());
    }
    if(jsonDecoder.hasDelay()){
        commandProcessor.setDelay(jsonDecoder.getValueDelay());
    }

}

void processIR(){
    irReceiver.receiveCode();
    if(irReceiver.hasChanged())
        commandProcessor.setInputCommand(irReceiver.getIRValue());
}

void processMic() {
  if(jsonDecoder.getBeatEnabled()){
      if(microphone.hasBass()){
          commandProcessor.bassFlicker();
      }
  }
}

void processInputCommand(){
    commandProcessor.processCommand();
}
