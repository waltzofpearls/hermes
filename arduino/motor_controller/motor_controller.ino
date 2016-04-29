#include <RBD_Motor.h>
#include <RBD_SerialManager.h>

// RBD::Motor constructor(pwm_pin, forward_pin, reverse_pin)
RBD::Motor motFrontL(11, 12, 13);
RBD::Motor motFrontR(9, 4, 5);
RBD::Motor motRearL(10, 7, 8);
RBD::Motor motRearR(6, 2, 3);
RBD::SerialManager ser;

void forward() {
  motFrontL.forward();
  motFrontR.forward();
  motRearL.forward();
  motRearR.forward();
  motFrontL.setSpeedPercent(95);
  motFrontR.setSpeedPercent(95);
  motRearL.setSpeedPercent(95);
  motRearR.setSpeedPercent(95);
  delay(250);
}

void reverse() {
  motFrontL.reverse();
  motFrontR.reverse();
  motRearL.reverse();
  motRearR.reverse();
  motFrontL.setSpeedPercent(95);
  motFrontR.setSpeedPercent(95);
  motRearL.setSpeedPercent(95);
  motRearR.setSpeedPercent(95);
  delay(250);
}

void turnLeft() {
  if (motFrontL.isReverse() && motFrontR.isForward()) {
    ser.println("already turning left, do nothing");
    return;
  }

  if (motFrontL.isReverse() && motFrontR.isReverse()) {
    ser.println("turning left while reversing");
    helpTurnRight();
    return;
  }

  helpTurnLeft();
}

void helpTurnLeft() {
  motFrontL.reverse();
  motRearL.reverse();
  motFrontR.forward();
  motRearR.forward();
  motFrontL.setSpeedPercent(95);
  motRearL.setSpeedPercent(95);
  motFrontR.setSpeedPercent(95);
  motRearR.setSpeedPercent(95);
  delay(250);
}

void turnRight() {
  if (motFrontL.isForward() && motFrontR.isReverse()) {
    ser.println("already turning right, do nothing");
    return;
  }

  if (motFrontL.isReverse() && motFrontR.isReverse()) {
    ser.println("turning right while reversing");
    helpTurnLeft();
    return;
  }

  helpTurnRight();
}

void helpTurnRight() {
  motFrontL.forward();
  motRearL.forward();
  motFrontR.reverse();
  motRearR.reverse();
  motFrontL.setSpeedPercent(95);
  motRearL.setSpeedPercent(95);
  motFrontR.setSpeedPercent(95);
  motRearR.setSpeedPercent(95);
  delay(250);
}

void stop() {
  motFrontL.off();
  motFrontR.off();
  motRearL.off();
  motRearR.off();
  delay(250);
}

void setup()
{
  ser.start();
}

void loop()
{
  if (ser.onReceive()) {
    if (ser.isCmd("forward") || ser.isCmd("f")) {
      forward();
      ser.println("forward!");
    } else if (ser.isCmd("reverse") || ser.isCmd("b")) {
      reverse();
      ser.println("reverse!");
    } else if (ser.isCmd("turnleft") || ser.isCmd("l")) {
      turnLeft();
      ser.println("turn left!");
    } else if (ser.isCmd("turnright") || ser.isCmd("r")) {
      turnRight();
      ser.println("turn right!");
    } else {
      stop();
      ser.println("stop!");
    }
  }
}
