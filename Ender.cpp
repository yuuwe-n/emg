#include <Servo.h> // Include the Servo library

int emg_pin = A0;
int value = 0;
int max_value = 0;
int min_value = 1023; // Initialize to maximum possible analog value
Servo myServo; // Create a servo object

// Servo pin
int servo_pin = 7;

void setup() {
  Serial.begin(9600);
  myServo.attach(servo_pin); // Attach the servo to the specified pin

  // Calibration
  Serial.println("HAVE YOUR ARM RELAXED");
  Serial.println("CALIBRATION IN: ");

  for (int i = 0 ; i < 3; i++) {
    Serial.println(3-i);
    delay(1000);
  }

  Serial.println("CALIBRATING");
  for (int i = 1 ; i <= 100; i++){
    value = analogRead(emg_pin);
    if (value > max_value) {
      max_value = value;
    }
    if (value < min_value) {
      min_value = value;
    }
    delay(100);
  }

  Serial.print("MAX VALUE: ");
  Serial.println(max_value); // Print the maximum value
  Serial.print("MIN VALUE: ");
  Serial.println(min_value); // Print the minimum value
  for(int i = 0; i < 10; i++){
    Serial.println();
  }
  Serial.println("CALIBRATION FINISHED");
  delay(3000);
}

void loop() {
  value = analogRead(emg_pin);

  // Map the EMG value to a servo angle (0 to 180 degrees)
  int servo_value = map(value, min_value, max_value, 0, 180);

  // Constrain the servo value to ensure it stays within 0 to 180 degrees
  servo_value = constrain(servo_value, 0, 180);

  myServo.write(servo_value); // Move the servo to the mapped angle
  Serial.print("EMG Value: ");
  Serial.print(value);
  Serial.print(" | Servo Angle: ");
  Serial.println(servo_value);

  delay(100);
}
