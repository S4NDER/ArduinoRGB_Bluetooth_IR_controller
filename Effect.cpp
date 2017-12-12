#include "Effect.h"
#include "Arduino.h"

Effect::Effect(void){

}

void Effect::flash (Color color){
    Color color_temp = color;
    color_temp.set_color(0,0,0);
    delay(500);
    color_temp.set_color(color.get_red(), color.get_green(), color.get_blue());
    controller.set_led(color_temp);
}

void Effect::normalize_to_color(Color color_temp, Color color_to_normalize_to, unsigned short int delaytime){
    unsigned char temp_red = color_temp.get_red();
    unsigned char temp_green = color_temp.get_green();
    unsigned char temp_blue = color_temp.get_blue();

    bool done_red = false;
    bool done_green = false;
    bool done_blue = false;

    while(!(done_red & done_green & done_blue)){
      if (color_temp.get_red() > color_to_normalize_to.get_red()) {
            temp_red --;
        } else if (color_temp.get_red() < color_to_normalize_to.get_red()) {
            temp_red ++;
        } else{
          done_red = true;
        }

        if (color_temp.get_green() > color_to_normalize_to.get_green()) {
            temp_green --;
        } else if (color_temp.get_green() < color_to_normalize_to.get_green()) {
            temp_green ++;
        } else{
          done_green = true;
        }


        if (color_temp.get_blue() > color_to_normalize_to.get_blue()) {
            temp_blue --;
        } else if (color_temp.get_blue() < color_to_normalize_to.get_blue()) {
            temp_blue ++;
        } else{
          done_blue = true;
        }

        color_temp.set_color(temp_red, temp_green, temp_blue);
        /*
        Serial.print("RGB(");
        Serial.print(temp_red);
        Serial.print(", ");
        Serial.print(temp_green);
        Serial.print(", ");
        Serial.print(temp_blue);
        Serial.print(")");

        Serial.print("    doneRGB(");
        Serial.print(done_red);
        Serial.print(", ");
        Serial.print(done_green);
        Serial.print(", ");
        Serial.print(done_blue);
        Serial.print(")");
        Serial.print("\r\n");
        */

        delay(delaytime);
        controller.set_led(color_temp);
   }
}

void Effect::cycle_rgb(void){
    normalize_to_color(Color(0,0,0), Color(255,0,0),5);
    normalize_to_color(Color(255,0,0), Color(0,255,0),5);
    normalize_to_color(Color(0,255,0), Color(0,0,255),5);
    normalize_to_color(Color(0,0,255), Color(0,0,0),5);
}
