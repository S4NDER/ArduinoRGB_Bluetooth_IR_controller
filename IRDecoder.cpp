#include "IRDecoder.h"

IRDecoder::IRDecoder (void){
    init();
}

void IRDecoder::init(void){
    Serial.begin(9600);
    startReceiver();
    Serial.println(F("Ready to receive IR signals"));
}

void IRDecoder::startReceiver(){
    receiver.enableIRIn(); // Start the receiver
}

void IRDecoder::receiveCode(void){
    if(receiver.getResults()){
        decodeData();
        startReceiver();
        if((decoder.value == 4294967295) || (decoder.value == 0)){
          isChanged = false;
          return;
        } else{
          irCode = decoder.value;
          isChanged = true;
        }
    } else {
        isChanged = false;
    }
}

void IRDecoder::decodeData(void){
    decoder.decode();
}

unsigned long IRDecoder::getIRValue(void){
  return irCode;
}

bool IRDecoder::hasChanged(void){
    return isChanged;
}
