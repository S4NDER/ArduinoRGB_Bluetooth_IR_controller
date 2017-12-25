#include "HC06.h"
#include "Microphone.h"
#include "IRDecoder.h"
#include "JSONDecoder.h"
#include "CommandProcessor.h"
#include "Defines.h"
#include "Color.h"
#include "Effect.h"
#include "LEDController.h"

#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

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
    thProcessInputCommand.run();
    //thMic.run();
}

void processBT(){
    jsonDecoder.decodeString(hc06.getInput());
    if (jsonDecoder.hasChanged()) {
      Serial.println("IR");
        if( jsonDecoder.getValueIRCode() > 0 ){
          commandProcessor.setInputCommand(jsonDecoder.getValueIRCode());
        }
    }
    if (jsonDecoder.hasRGBInput()) {
      Serial.println("RGB");
        commandProcessor.setInputCommand(BT_COMMAND);
        commandProcessor.setRGBColor(jsonDecoder.getValueRed(), jsonDecoder.getValueGreen(), jsonDecoder.getValueBlue());
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
          commandProcessor.setInputCommand(MIC_FLASH);
      }
  }
}

void processInputCommand(){
    commandProcessor.processCommand();
}
