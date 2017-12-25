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
        return decoder.value;
    }
    return 0;
}

void IRDecoder::decodeData(void){
    decoder.decode();
}
