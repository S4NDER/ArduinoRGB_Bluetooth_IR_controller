#include "HC06.h"

HC06::HC06 (void){
    init();
}

void HC06::init(void){
    BT.begin(9600);
}
/*
char HC06::getData(void){
    String input = getInput();
    char *data[DATA_BUFFER];
    if(input.charAt(input.length()-1) == '}'){                                  //Message has valid end
        for (unsigned short int i = 0; i < input.length(); i++) {               //Parsing string into char array
            data[i] = input[i];
        }
    }
    return *data;
}
*/

String HC06::getInput(void){
    String input = "";
    if(BT.available()){                                                         //Receive data if available
        while (BT.available()) {                                                //"Keep receiving"
            delay(10);                                                          //Delay to make it stable
            char inputStream = BT.read();                                       //Read each character one by one
            input += inputStream;                                               //Append read character to input string

            if(inputStream == '}'){                                             //End of message
                break;
            }
            if((inputStream == '{') && (input.length() > 1)){                   //Invalid restart of message
                input = "";
                break;
            }
            if (input.charAt(0) != '{') {                                       //Invalid start of message
                input = "";
                break;
            }
        }
    }
    if(Serial.available()){
        delay(10);
        BT.write(Serial.read());
    }
    return input;
}
