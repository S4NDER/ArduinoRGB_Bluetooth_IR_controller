#include <ArduinoJson.h>

#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

#include <SoftwareSerial.h>

#include <stdlib.h>

#include <IRLibDecodeBase.h>
#include <IRLib_P01_NEC.h>
#include <IRLibCombo.h>
#include <IRLibRecvPCI.h>

#include "Color.h"
#include "Effect.h"
#include "LEDController.h"

#define BT_COMMAND 1

#define IR_BRIGHT_UP  0xF700FF
#define IR_BRIGHT_DOWN 0xF7807F
#define IR_OFF 0xF740BF
#define IR_ON  0xF7C03F

#define IR_FLASH 0xF7D02F
#define IR_STROBE  0xF7F00F
#define IR_FADE  0xF7C837
#define IR_SMOOTH  0xF7E817

#define IR_RED  0xF720DF
#define IR_GREEN 0xF7A05F
#define IR_BLUE  0xF7609F
#define IR_WHITE 0xF7E01F

#define IR_ORANGE  0xF710EF
#define IR_DARK_YELLOW 0xF730CF
#define IR_YELLOW 0xF708F7
#define IR_STRAW_YELLOW 0xF728D7

#define IR_PEA_GREEN 0xF7906F
#define IR_CYAN  0xF7B04F
#define IR_LIGHT_BLUE  0xF78877
#define IR_SKY_BLUE  0xF7A857

#define IR_DARK_BLUE  0xF750AF
#define IR_DARK_PINK 0xF7708F
#define IR_PINK  0xF748B7
#define IR_PURPLE  0xF76897

Color color;
Color last_color;
Effect effect;
LEDController controller;

unsigned char rgb_red = 0;
unsigned char rgb_green = 0;
unsigned char rgb_blue = 0;

unsigned char bt_red = 0;
unsigned char bt_green = 0;
unsigned char bt_blue = 0;
unsigned short int bt_delay = 0;

bool rgb_red_done = false;
bool rgb_green_done = false;
bool rgb_blue_done = false;

Thread read_ir_thread = Thread();
Thread process_ir_thread = Thread();
Thread th_listen_to_BT = Thread();
unsigned long last_value = IR_RED;
unsigned long live_IR_value = IR_RED;

StaticJsonBuffer<320> jsonBuffer;

//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(2);

//Create a decoder object
IRdecode myDecoder;
String command = ""; // Stores response of bluetooth device

SoftwareSerial BT(11, 12); // RX, TX

void setup() {
    controller.set_led(color);
    effect.set_controller(controller);
    pinMode(LED_BUILTIN, OUTPUT); //Used for status LED
    BT.begin(9600);
    Serial.begin(9600);
    myReceiver.enableIRIn(); // Start the receiver
    Serial.println(F("Ready to receive IR signals"));
    

    //Setting timeintervals (ms) for threads
    read_ir_thread.setInterval(2);
    th_listen_to_BT.setInterval(10);
    process_ir_thread.setInterval(10);

    //Function to run in the thread
    read_ir_thread.onRun(listen_to_IR);
    th_listen_to_BT.onRun(listen_to_BT);
    process_ir_thread.onRun(execute_IR_commands);
}

void loop() {
    if(read_ir_thread.shouldRun()){
        read_ir_thread.run();
    }

    if(process_ir_thread.shouldRun()){
        process_ir_thread.run();
    }

    if(th_listen_to_BT.shouldRun()){
        th_listen_to_BT.run();
    }
}

void listen_to_BT(){
    if (BT.available ()) // receive data if available.
    {
        while (BT.available ()) // "keep receiving".
        {
            
            char c = BT.read (); // Conduct serial read
            command += c; // Build the string.
            if(c == '}'){
              break;
            }
            delay (10); // Delay added to make thing stable
        }
        Serial.println(command);
        char data[315];
        for(int i = 0; i < command.length(); i++){
            data[i] = command[i];
        }
        
        JsonObject& root = jsonBuffer.parseObject(data);

        bt_red = root["red"];
        bt_green = root["green"];
        bt_blue = root["blue"];
        bt_delay = root["delay"];
        String bt_ir_val = root["ir_val"];

        char bt_data[128];
        for(int i = 0; i < bt_ir_val.length(); i++){
            bt_data[i] = bt_ir_val[i];
        }
        if(bt_ir_val.length() > 3){
          sscanf(bt_data,"%lX", &live_IR_value); // string to long
        } else {
          live_IR_value = BT_COMMAND;
        }
        jsonBuffer.clear();
        blink_led(); 

        command = ""; // No repeats
    }
    if (Serial.available ())
    {
        delay (10);
        BT.write (Serial.read ());
    }
}

void listen_to_IR(){
    if (myReceiver.getResults()) {
        jsonBuffer.clear();
        myDecoder.decode();           //Decode it
        live_IR_value = myDecoder.value;
        blink_led();
        myReceiver.enableIRIn();      //Restart receiver
    }

}

void blink_led(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void execute_IR_commands(){
  jsonBuffer.clear();
    switch(live_IR_value){
        case IR_WHITE:
        color.WHITE;
        last_color.WHITE;
        controller.set_led(color);
        last_value = IR_WHITE;
        break;
        
        case IR_RED:
        color.RED;
        last_color.RED;
        controller.set_led(color);
        last_value = IR_RED;
        break;
        
        case IR_GREEN:
        color.GREEN;
        last_color.GREEN;
        controller.set_led(color);
        last_value = IR_GREEN;
        break;
        
        case IR_BLUE:
        color.BLUE;
        last_color.BLUE;
        controller.set_led(color);
        last_value = IR_BLUE;
        break;
        
        case IR_ORANGE:
        color.ORANGE;
        last_color.ORANGE;
        controller.set_led(color);
        last_value = IR_ORANGE;
        break;
        
        case IR_DARK_YELLOW:
        color.DARK_YELLOW;
        last_color.DARK_YELLOW;
        controller.set_led(color);
        last_value = IR_DARK_YELLOW;
        break;
        
        case IR_YELLOW:
        color.YELLOW;
        last_color.YELLOW;
        controller.set_led(color);
        last_value = IR_YELLOW;
        break;
        
        case IR_STRAW_YELLOW:
        color.STRAW_YELLOW;
        last_color.STRAW_YELLOW;
        controller.set_led(color);
        last_value = IR_STRAW_YELLOW;
        break;
        
        case IR_PEA_GREEN:
        color.PEA_GREEN;
        last_color.PEA_GREEN;
        controller.set_led(color);
        last_value = IR_PEA_GREEN;
        break;
        
        case IR_CYAN:
        color.CYAN;
        last_color.CYAN;
        controller.set_led(color);
        last_value = IR_CYAN;
        break;
        
        case IR_LIGHT_BLUE:
        color.LIGHT_BLUE;
        last_color.LIGHT_BLUE;
        controller.set_led(color);
        last_value = IR_LIGHT_BLUE;
        break;
        
        case IR_SKY_BLUE:
        color.SKY_BLUE;
        last_color.SKY_BLUE;
        controller.set_led(color);
        last_value = IR_SKY_BLUE;
        break;
        
        case IR_DARK_BLUE:
        color.DARK_BLUE;
        last_color.DARK_BLUE;
        controller.set_led(color);
        last_value = IR_DARK_BLUE;
        break;
        
        case IR_DARK_PINK:
        color.DARK_PINK;
        last_color.DARK_PINK;
        controller.set_led(color);
        last_value = IR_DARK_PINK;
        break;
        
        case IR_PINK:
        color.PINK;
        last_color.PINK;
        controller.set_led(color);
        last_value = IR_PINK;
        break;
        
        case IR_PURPLE :
        color.PURPLE;
        last_color.PURPLE;
        controller.set_led(color);
        last_value = IR_PURPLE;
        break;
        
        case IR_BRIGHT_UP :
        live_IR_value = 0;
        effect.bright_up(color);
        break;
        
        case IR_BRIGHT_DOWN:
        live_IR_value = 0;
        effect.bright_down(color);
        break;
        
        case IR_OFF:
        //color.OFF;
        controller.turn_off();
        controller.set_led(color);
        break;

        case IR_ON:
        controller.turn_on();
        controller.set_led(last_color);
        break;
        
        case IR_FLASH:
        last_value = IR_FLASH;
        color.WHITE;
        last_color.WHITE;
        controller.set_led(color);
        delay(200);
        color.RED;
        last_color.RED;
        controller.set_led(color);
        delay(200);
        color.GREEN;
        last_color.GREEN;
        controller.set_led(color);
        delay(200);
        color.BLUE;
        last_color.BLUE;
        controller.set_led(color);
        delay(200);
        color.ORANGE;
        last_color.ORANGE;
        controller.set_led(color);
        delay(200);
        color.DARK_YELLOW;
        last_color.DARK_YELLOW;
        controller.set_led(color);
        delay(200);
        color.YELLOW;
        last_color.YELLOW;
        controller.set_led(color);
        delay(200);
        color.STRAW_YELLOW;
        last_color.STRAW_YELLOW;
        controller.set_led(color);
        delay(200);
        color.PEA_GREEN;
        last_color.PEA_GREEN;
        controller.set_led(color);
        delay(200);
        color.CYAN;
        last_color.CYAN;
        controller.set_led(color);
        delay(200);
        color.LIGHT_BLUE;
        last_color.LIGHT_BLUE;
        controller.set_led(color);
        delay(200);
        color.SKY_BLUE;
        last_color.SKY_BLUE;
        controller.set_led(color);
        delay(200);
        color.DARK_BLUE;
        last_color.DARK_BLUE;
        controller.set_led(color);
        delay(200);
        color.DARK_PINK;
        last_color.DARK_PINK;
        controller.set_led(color);
        delay(200);
        color.PINK;
        last_color.PINK;
        controller.set_led(color);
        delay(200);
        color.PURPLE;
        last_color.PURPLE;
        controller.set_led(color);
        delay(200);
        break;
        case IR_STROBE:
        effect.flash(color, 200);
        last_value = IR_STROBE;
        break;

        case IR_FADE:
        last_value = IR_FADE;
        break;
        
        case IR_SMOOTH:
        last_value = IR_SMOOTH;
        break;

        case BT_COMMAND:
        color.set_color(bt_red, bt_green, bt_blue);
        last_color.set_color(bt_red, bt_green, bt_blue);
        controller.set_led(color);
        last_value = BT_COMMAND;
        break; 
        
    }
    if(live_IR_value != IR_FADE){
        rgb_red = 0;
        rgb_green = 0;
        rgb_blue = 0;
    }

    if(last_value == IR_SMOOTH){
      unsigned char i = 0;
      for(i = 0; i < 25 ; i++){
          effect.bright_down(color);
          delay(100);
      }
      for(i = 25; i > 0 ; i--){
          effect.bright_up(color);
          delay(100);
      }
    }
    
    if(live_IR_value == IR_STROBE){
        effect.flash(color, 200);
    }
    if(last_value == IR_FADE){
        if(!rgb_red_done){
            if(rgb_red == 255){
                rgb_red_done = true;
                rgb_green_done = false;
            } else{
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red+1),(rgb_green),(rgb_blue)),2);
                rgb_red ++;
                rgb_green_done = true;
                rgb_blue_done = true;
            }
        }


        if(!rgb_green_done){
            if(rgb_green == 255){
                rgb_green_done = true;
                rgb_blue_done = false;
            } else{
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green+1),(rgb_blue)),2);
                rgb_green ++;
                rgb_red --;
                rgb_blue_done = true;
            }
        }

        if(!rgb_blue_done){
            if(rgb_blue == 255){
                rgb_blue_done = true;
            } else{
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green),(rgb_blue+1)),2);
                rgb_blue ++;
                rgb_green --;
            }
        }

        if(rgb_red_done & rgb_green_done & rgb_blue_done){
            if(rgb_blue == 0){
                rgb_red_done = false;
            } else {
                effect.normalize_to_color(Color(rgb_red, rgb_green, rgb_blue),Color((rgb_red),(rgb_green),(rgb_blue-1)),2);
                rgb_blue --;
            }
        }
        color.set_color(rgb_red,rgb_green, rgb_blue);
    }
}
