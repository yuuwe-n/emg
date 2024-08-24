#include <Servo.h>

//Servo servo;
const int MAX_ANGLE = 180;

int emg_pin = A0;
int value = 0;
int min_value = 0;
int max_value = 0;

float norm_value = 0;
int angle = 0;

const int freq = 10; // 60 refreshes per second
const int period = 1000 / freq; // ms per period

void setup() {
  Serial.begin(9600);

  // servo intialization
//  servo.attach(13); // attach(<pin number>)
//  servo.write(0);

  // calibration
  Serial.println("HAVE YOUR ARM RELAXED");
  Serial.println("CALIBRATION IN: ");

  for (int i = 0 ; i < 3; i++) {
    Serial.println(3-i);
    delay(1000);
  }


  Serial.println("CALIBRATING RELAXED");
  for (int i = 1 ; i <= 100; i++){
    value = analogRead(emg_pin);
    if (value > min_value) {
      min_value = value;
    }
    delay(100);
  }

  Serial.println("HAVE YOUR ARM CONTRACTED");
  Serial.println("CALIBRATION IN: ");

  for (int i = 0 ; i < 3; i++) {
    Serial.println(3-i);
    delay(1000);
  }


  Serial.println("CALIBRATING CONTRACTION");
  for (int i = 1 ; i <= 50; i++){
    value = analogRead(emg_pin);
    if (value > max_value) {
      max_value = value;
    }
    delay(100);
  }

  Serial.println("MIN VALUE: ");
  Serial.println(min_value); // convert min_value to string and append
  Serial.println("MAX VALUE: ");
  Serial.println(max_value); // convert min_value to string and append
  delay(1000);
  for(int i = 0; i<10;i++){Serial.println();}
  Serial.println("CALIBRATION FINISHED");
  delay(3000);
}


void loop() {
  value = analogRead(emg_pin);

  if (value < min_value) {
    value = min_value;
    norm_value = 0.00;
  } else if (value > max_value) {
    value = max_value;
    norm_value = 1.00;
  } else {
    norm_value = static_cast<float>(value - min_value) / (max_value - min_value);
  }
  
  Serial.println(norm_value);
  angle = static_cast<int>(norm_value * MAX_ANGLE);
//  servo.write(angle);

  Serial.println(value);

  delay(period); // refresh period
}
