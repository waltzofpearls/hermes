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
  motFrontL.setSpeedPercent(50);
  motFrontR.setSpeedPercent(50);
  motRearL.setSpeedPercent(50);
  motRearR.setSpeedPercent(50);
  delay(250);
}

void reverse() {
  motFrontL.reverse();
  motFrontR.reverse();
  motRearL.reverse();
  motRearR.reverse();
  motFrontL.setSpeedPercent(50);
  motFrontR.setSpeedPercent(50);
  motRearL.setSpeedPercent(50);
  motRearR.setSpeedPercent(50);
  delay(250);
}

void turnLeft() {
  if (motFrontL.isForward()) {
    motFrontL.reverse();
    motRearL.reverse();
    motFrontR.forward();
    motRearR.forward();
  } else {
    motFrontL.forward();
    motRearL.forward();
    motFrontR.reverse();
    motRearR.reverse();
  }
  motFrontL.setSpeedPercent(50);
  motFrontR.setSpeedPercent(50);
  motRearL.setSpeedPercent(50);
  motRearR.setSpeedPercent(50);
  delay(250);
}

void turnRight() {
  if (motFrontL.isForward()) {
    motFrontL.forward();
    motRearL.forward();
    motFrontR.reverse();
    motRearR.reverse();
  } else {
    motFrontL.reverse();
    motRearL.reverse();
    motFrontR.forward();
    motRearR.forward();
  }
  motFrontL.setSpeedPercent(50);
  motFrontR.setSpeedPercent(50);
  motRearL.setSpeedPercent(50);
  motRearR.setSpeedPercent(50);
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
    if (ser.isCmd("forward")) {
      forward();
      ser.println("forward!");
    } else if (ser.isCmd("reverse")) {
      reverse();
      ser.println("reverse!");
    } else if (ser.isCmd("turnleft")) {
      turnLeft();
      ser.println("turn left!");
    } else if (ser.isCmd("turnright")) {
      turnRight();
      ser.println("turn right!");
    } else {
      stop();
      ser.println("stop!");
    }
  }
}
