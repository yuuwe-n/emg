int emg_pin = A0;
int value = 0;
int max_value = 0;

int c_pin = 2; // calibration pin
int r_pin = A5; // running pin



// TODO
// 1. Calibration
// 2. cvs file

void setup() {
  Serial.begin(9600);
  pinMode(c_pin, OUTPUT);

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
    if (value > max_value) {
      max_value = value;
    }
    delay(100);
  }

  Serial.println("MAX VALUE: ");
  Serial.println(max_value); // convert max_value to string and append
  for(int i = 0; i<10;i++){Serial.println();}
  Serial.println("CALIBRATION FINISHED");
  delay(3000);

}

void loop() {
  value = analogRead(emg_pin);

  if (value < max_value) {
    value = 0;
  }

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
