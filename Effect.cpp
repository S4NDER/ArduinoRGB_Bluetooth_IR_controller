#include "Effect.h"
#include "Arduino.h"

#define RED Color(255,0,0)
#define GREEN Color(0,255,0)
#define BLUE Color(0,0,255)
#define OFF Color(0,0,0)



Effect::Effect(void){

}

void Effect::flash (Color color, unsigned short int delaytime){
    controller.set_led(color);
    delay(delaytime);
    controller.set_led(OFF);
    delay(delaytime);
}
void Effect::bright_up(Color &color_temp){
    if(color_temp.get_red()*1.1 <= 255){
      temp_red = color_temp.get_red()*1.1;
    }
    if(color_temp.get_red() == 0){
      temp_red = 0;
    }
    if(color_temp.get_green()*1.1 <= 255){
      temp_green= color_temp.get_green()*1.1;
    }
    if(color_temp.get_green() == 0){
      temp_green = 0;
    }
    if(color_temp.get_blue()*1.1 <= 255){
      temp_blue = color_temp.get_blue()*1.1;
    }
    if(color_temp.get_blue() == 0){
      temp_blue = 0;
    }
    color_temp.set_color(temp_red, temp_green, temp_blue);
    controller.set_led(color_temp);
}

void Effect::bright_down(Color &color_temp){
    if(color_temp.get_red()/1.1 > 5){
      temp_red = color_temp.get_red()/1.1;
    }
    if(color_temp.get_red() == 0){
      temp_red = 0;
    }
    if(color_temp.get_green()/1.1 > 5){
      temp_green = color_temp.get_green()/1.1;
    }
    if(color_temp.get_green() == 0){
      temp_green = 0;
    }
    if(color_temp.get_blue()/1.1 > 5){
      temp_blue = color_temp.get_blue()/1.1;
    }
    if(color_temp.get_blue() == 0){
      temp_blue = 0;
    }
    color_temp.set_color(temp_red, temp_green, temp_blue);
    controller.set_led(color_temp);
}

void Effect::normalize_to_color(Color color_temp, Color color_to_normalize_to, unsigned short int delaytime){
    temp_red = color_temp.get_red();
    temp_green = color_temp.get_green();
    temp_blue = color_temp.get_blue();

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
        delay(delaytime);
        controller.set_led(color_temp);
   }

}

void Effect::cycle_rgb(unsigned short int delaytime){
    normalize_to_color(OFF, RED,delaytime);
    normalize_to_color(RED, GREEN,delaytime);
    normalize_to_color(GREEN, BLUE,delaytime);
    normalize_to_color(BLUE, OFF,delaytime);
}

void Effect::cycly_rgb(void){
  cycle_rgb(5);
}
