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
        jsonBuffer.clear();

        if(findText("red", input)){
            red = root["red"];
            rgbInput = true;
        }
        if(findText("green", input)){
            green = root["green"];
            rgbInput = true;
        }
        if(findText("blue", input)){
            blue = root["blue"];
            rgbInput = true;
        }
        if(findText("delay", input)){
            delayTime = root["delay"];
            Serial.println(delayTime);
            isDelay = true;
        }
        if(findText("ir_val", input)){
            String tempIRCode = root["ir_val"];
            char chTempIRCode[128];
            for (unsigned char i = 0; i < tempIRCode.length(); i++) {
                chTempIRCode[i] = tempIRCode[i];
            }
            if (tempIRCode.length() > 7) {
                sscanf(chTempIRCode,"%lX", &valueIRCode);
                isChanged = true;
                rgbInput = false;
            }
        }
        if(findText("beats", input)){
            beatsEnabled = root["beats"];
        }
    } else {
      isChanged = false;
      rgbInput = false;
      isDelay = false;
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

bool JSONDecoder::getBeatEnabled (void){
    return beatsEnabled;
}

bool JSONDecoder::hasChanged (void){
    return isChanged;
}

bool JSONDecoder::hasRGBInput (void){
    return rgbInput;
}

bool JSONDecoder::hasDelay(void){
    return isDelay;
}

bool JSONDecoder::findText(String word, String text) {
  for (int i = 0; i <= text.length() - word.length(); i++) {
    if (text.substring(i,word.length()+i) == word) {
      return true;
    }
  }
  return false;
}
