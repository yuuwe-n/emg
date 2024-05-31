#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
}

void loop() {
  Serial.begin(9600);
  // put your main code here, to run repeatedly:
  
  // counter clockwise
  for (int i = 0; i <= 180; i++){
    servo.write(i);
    Serial.println(i);

    delay(15);
  }

  // clockwise
  for (int i = 180; i >= 0; i--){
    servo.write(i);
    Serial.println(i);
    delay(10);
  }
}