#include "Color.h"
#include "Effect.h"
#include "LEDController.h"

Color color;
Effect effect;
LEDController controller;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
    effect.cycle_rgb();
}
