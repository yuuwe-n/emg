#include <Stepper.h>


#define STEPS 2048

// USE THESE PINS ACCORDINGLY
int in1 = 13;
int in2 = 12;
int in3 = 11;
int in4 = 10;

Stepper stepper = Stepper(STEPS, in1, in3, in2, in4);


int emg_pin = A0;
int value = 0;
int threshold = 0;

void setup() {
  Serial.begin(9600);

  // calibration
  Serial.println("HAVE YOUR ARM RELAXED");
  Serial.println("CALIBRATION IN: ");

  for (int i = 0 ; i < 3; i++) {
    Serial.println(3-i);
    delay(1000);
  }


  Serial.println("CALIBRATING");
  for (int i = 1 ; i <= 100; i++){
    value = analogRead(emg_pin);
    if (value > threshold) {
      threshold = value;
    }
    delay(100);
  }

  Serial.println("THRESHOLD: ");
  Serial.println(threshold); // convert threshold to string and append
  for(int i = 0; i<10;i++){Serial.println();}
  Serial.println("CALIBRATION FINISHED");
  delay(3000);

  stepper.setSpeed(15);

}

void loop() {
  value = analogRead(emg_pin);

  if (value < threshold) {
    value = 0;

    // EDIT THIS VALUE FOR AMOUNT OF STEPS TO STEP WHEN NOT CONTRACTING
    stepper.step(-100);
  }  else {

    // EDIT THIS VALUE FOR AMOUNT OF STEPS TO STEP WHEN CONTRACTING
    stepper.step(100);
  }


  Serial.println(value);
  delay(100);



}
