#include "JSONDecoder.h"

bool JSONDecoder::beatsEnabled = false;

JSONDecoder::JSONDecoder (void){

}

void JSONDecoder::decodeString(String input){
    if (input.charAt(input.length()-1) == '}') {
        const char *data = input.c_str();

        StaticJsonBuffer<JSON_BUFFER> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(data);
        jsonBuffer.clear();
        char * output = NULL;
        output = strstr(data, "red");
        if(output){
            red = root["red"];
            rgbInput = true;
        }
        output = strstr(data,"green");
        if(output){
            green = root["green"];
            rgbInput = true;
        }
        output = strstr(data,"blue");
        if(output){
            blue = root["blue"];
            rgbInput = true;
        }
        output = strstr(data,"delay");
        if(output){
            delayTime = root["delay"];
            Serial.println(delayTime);
            isDelay = true;
        }
        output = strstr(data,"ir_val");
        if(output){
            String tempIRCode = root["ir_val"];
            const char *chTempIRCode = tempIRCode.c_str();
            if (tempIRCode.length() > 7) {
                sscanf(chTempIRCode,"%lX", &valueIRCode);
                isChanged = true;
                rgbInput = false;
            }
        }
        output = strstr(data,"beats");
        if(output){
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
