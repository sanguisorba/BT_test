#include <ESP32Servo.h>
 
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
Servo myservo1;
Servo myservo2;
void setup() {
  SerialBT.begin("ESP32_TEST");
  myservo1.attach(13); // Servo1 pin = 13
  myservo2.attach(12); // Servo2 pin = 12
  myservo1.write(90);
  myservo2.write(90);
}
 
void loop() {
  if (SerialBT.available()) {
    String mot = SerialBT.readStringUntil(',');
    String deg = SerialBT.readStringUntil('Z');
// Z is a symbol used to indicate the end of communication.
    if (mot.toInt() == 1) {
      myservo1.write(deg.toInt());
    }
    if (mot.toInt() == 2) {
      myservo2.write(deg.toInt());
    }
   }
}
