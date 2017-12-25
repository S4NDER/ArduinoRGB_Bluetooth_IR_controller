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

unsigned long IRDecoder::getCode(void){
    if(receiver.getResults()){
        decodeData();
        startReceiver();
        irCode = decoder.value;
    }
    return irCode;
}

void IRDecoder::decodeData(void){
    decoder.decode();
}

//TODO
/*
Create method that returns boolean and keeps a previous state of the IRCommand to track if there is a change
*/
