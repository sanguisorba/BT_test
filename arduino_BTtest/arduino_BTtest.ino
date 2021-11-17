#include <Servo.h>
 
Servo myservo1;
Servo myservo2;
void setup() {
  Serial.begin(38400);
  myservo1.attach(3); // Servo1 pin = 3
  myservo2.attach(9); // Servo2 pin = 9
}
 
void loop() {
  if (Serial.available()) {
    String mot = Serial.readStringUntil(',');
    String deg = Serial.readStringUntil('Z');
// Z is a symbol used to indicate the end of communication.
    if (mot.toInt() == 1) {
      myservo1.write(deg.toInt());
    }
    if (mot.toInt() == 2) {
      myservo2.write(deg.toInt());
    }
   }
}
