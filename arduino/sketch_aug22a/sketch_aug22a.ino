float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#include <Servo.h>

Servo servo;
int angle = 0;
const int MAX_ANGLE = 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(13); // attach(<pin number>)
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  float voltage = floatMap(value, 0, 1023, 0, 5);
  // print out the value you read:

  int angle = map(value, 0 , 1023, 140, 180);

  //Serial.print("Analog: ");
  //Serial.print(value);
  Serial.print(", angle: ");
  Serial.print(angle);
  //Serial.print(", Voltage: ");
  //Serial.println(voltage);

  servo.write(angle);
  //servo.write(180);
  //for (int i =180; i >= 140; i--){
  //  servo.write(i);
  //  Serial.println(i);
  //  delay(100);
  //}

  delay(100);
  

}
