#include "../headers/HC06.h"

namespace ArduinoRGB{

HC06::HC06 (void){
    init();
}

void HC06::init(void){
    BT.begin(9600);
}

String HC06::getInput(void){
    String input = "";
    if(BT.available()){                                                   //Receive data if available
        while (BT.available()) {                                          //"Keep receiving"
        delay(10);                                                        //Delay to make it stable
        char inputStream = BT.read();                                     //Read each character one by one
        input += inputStream;                                             //Append read character to input string

        if(inputStream == '}'){                                           //End of message
            break;
        }
        if((inputStream == '{') && (input.length() > 1)){                 //Invalid restart of message
            input = "";
            break;
        }
        if (input.charAt(0) != '{') {                                     //Invalid start of message
            input = "";
            break;
        }
    }
    Serial.println(input);
}
if(Serial.available()){
    delay(10);
    BT.write(Serial.read());
}
return input;
}
};
