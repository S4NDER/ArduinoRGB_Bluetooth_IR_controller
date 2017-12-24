#include "JSONDecoder.h"

JSONDecoder::JSONDecoder (void){

}

void JSONDecoder::decodeString(String input){
    if (input.charAt(input.length()-1) == '}') {
        char data[DATA_BUFFER];
        for (unsigned short int i = 0; i < input.length(); i++) {
            data[i] = input[i];
        }
        StaticJsonBuffer<JSON_BUFFER> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(data);

        red = root["red"];
        green = root["green"];
        blue = root["blue"];
        delayTime = root["delay"];
        String tempIRCode = root["ir_val"];

        if (root["beats"] = 't') {
            beatsEnabled = true;
        } else if (root["beats"] = 'f') {
            beatsEnabled = false;
        }
        char chTempIRCode[128];
        for (unsigned char i = 0; i < tempIRCode.length(); i++) {
            chTempIRCode[i] = tempIRCode[i];
        }
        if (tempIRCode.length() > 3) {
            sscanf(chTempIRCode,"%lX", &valueIRCode);
        }
    }
}

unsigned char JSONDecoder::getValueRed (void){
    return red;
}

unsigned char JSONDecoder::getValueGreen (void){
    return green;
}

unsigned char JSONDecoder::getValueBlue (void){
    return blue;
}

unsigned short int JSONDecoder::getValueDelay (void){
    return delayTime;
}

unsigned long JSONDecoder::getValueIRCode (void){
    return valueIRCode;
}

bool JSONDecoder::getBeatEnabled(void){
    return beatsEnabled;
}
