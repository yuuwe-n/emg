int emg_pin = A0;
int value = 0;

int c_pin = 2; // calibration pin
int r_pin = A5; // running pin

void setup() {
  Serial.begin(9600);
  pinMode(c_pin, OUTPUT);
}

void loop() {
  value = analogRead(emg_pin);

  /*
  if (value > 700) {
    value = 1;
  } else {
    value = 0;
  }
  */

  Serial.println(value);
  delay(100);
  //digitalWrite(c_pin, HIGH);

  /*
  digitalWrite(c_pin, LOW);
  delay(1000);
  digitalWrite(c_pin, HIGH);
  delay(1000);
  */



}
