#include <Stepper.h>


#define STEPS 2048

int in1 = 13;
int in2 = 12;
int in3 = 11;
int in4 = 10;


Stepper stepper = Stepper(STEPS, in1, in3, in2, in4);

void setup() {
  stepper.setSpeed(15);
  Serial.begin(9600);

}


void loop() {
  stepper.step(STEPS);
  delay(500);
  stepper.step(-STEPS);

}