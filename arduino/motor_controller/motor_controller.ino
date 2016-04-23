#include <AFMotor.h>

AF_DCMotor motorFrontLeft(3);
AF_DCMotor motorFrontRight(2);
AF_DCMotor motorRearLeft(4);
AF_DCMotor motorRearRight(1);

String serialInput = "";

void setup() {
  Serial.begin(9600);

  motorFrontLeft.setSpeed(100);
  motorFrontRight.setSpeed(100);
  motorRearLeft.setSpeed(100);
  motorRearRight.setSpeed(100);

  motorFrontLeft.run(RELEASE);
  motorFrontRight.run(RELEASE);
  motorRearLeft.run(RELEASE);
  motorRearRight.run(RELEASE);
}

void loop() {
  while (Serial.available()) {
    delay(3);
    if (Serial.available() > 0) {
      char c = Serial.read();
      serialInput += c;
    } 
  }
  if (serialInput.length() > 0) {
    if (serialInput == "forward") {
      motorFrontLeft.run(FORWARD);
      motorFrontRight.run(FORWARD);
      motorRearLeft.run(FORWARD);
      motorRearRight.run(FORWARD);
    } else if (serialInput == "backward") {
      motorFrontLeft.run(BACKWARD);
      motorFrontRight.run(BACKWARD);
      motorRearLeft.run(BACKWARD);
      motorRearRight.run(BACKWARD);
    } else {
      motorFrontLeft.run(RELEASE);
      motorFrontRight.run(RELEASE);
      motorRearLeft.run(RELEASE);
      motorRearRight.run(RELEASE);
    }
  }
  serialInput = "";
}
