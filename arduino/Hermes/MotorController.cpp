#include "Arduino.h"
#include "MotorController.h"

MotorController::MotorController(RBD::SerialManager ser)
  // RBD::Motor constructor(pwm_pin, forward_pin, reverse_pin)
  : _motorFrontL(MOTOR_FL_PWM, MOTOR_FL_FORWARD, MOTOR_FL_REVERSE)
  , _motorFrontR(MOTOR_FR_PWM, MOTOR_FR_FORWARD, MOTOR_FR_REVERSE)
  , _motorRearL(MOTOR_RL_PWM, MOTOR_RL_FORWARD, MOTOR_RL_REVERSE)
  , _motorRearR(MOTOR_RR_PWM, MOTOR_RR_FORWARD, MOTOR_RR_REVERSE)
{
  _serial = ser;
}

void MotorController::forward() {
  _motorFrontL.forward();
  _motorFrontR.forward();
  _motorRearL.forward();
  _motorRearR.forward();

  _motorFrontL.setSpeedPercent(95);
  _motorFrontR.setSpeedPercent(95);
  _motorRearL.setSpeedPercent(95);
  _motorRearR.setSpeedPercent(95);

  delay(250);
  _serial.println("Forward");
}

void MotorController::backward() {
  _motorFrontL.reverse();
  _motorFrontR.reverse();
  _motorRearL.reverse();
  _motorRearR.reverse();

  _motorFrontL.setSpeedPercent(95);
  _motorFrontR.setSpeedPercent(95);
  _motorRearL.setSpeedPercent(95);
  _motorRearR.setSpeedPercent(95);

  delay(250);
  _serial.println("Backward");
}

void MotorController::stop() {
  _motorFrontL.off();
  _motorFrontR.off();
  _motorRearL.off();
  _motorRearR.off();

  _motorFrontL.forward();
  _motorFrontR.forward();
  _motorRearL.forward();
  _motorRearR.forward();

  delay(250);
  _serial.println("Stop");
}

void MotorController::turnLeft() {
  if (_motorFrontL.isReverse() && _motorFrontR.isForward()) {
    _serial.println("already turning left, do nothing");
    return;
  }

  if (_motorFrontL.isReverse() && _motorFrontR.isReverse()) {
    _serial.println("turning left while going backward");
    _helpTurnRight();
    return;
  }

  _helpTurnLeft();
}

void MotorController::_helpTurnLeft() {
  _motorFrontL.reverse();
  _motorRearL.reverse();
  _motorFrontR.forward();
  _motorRearR.forward();

  _motorFrontL.setSpeedPercent(95);
  _motorRearL.setSpeedPercent(95);
  _motorFrontR.setSpeedPercent(95);
  _motorRearR.setSpeedPercent(95);

  delay(250);
  _serial.println("Turn left");
}

void MotorController::turnRight() {
  if (_motorFrontL.isForward() && _motorFrontR.isReverse()) {
    _serial.println("already turning right, do nothing");
    return;
  }

  if (_motorFrontL.isReverse() && _motorFrontR.isReverse()) {
    _serial.println("turning right while going backward");
    _helpTurnLeft();
    return;
  }

  _helpTurnRight();
}

void MotorController::_helpTurnRight() {
  _motorFrontL.forward();
  _motorRearL.forward();
  _motorFrontR.reverse();
  _motorRearR.reverse();

  _motorFrontL.setSpeedPercent(95);
  _motorRearL.setSpeedPercent(95);
  _motorFrontR.setSpeedPercent(95);
  _motorRearR.setSpeedPercent(95);

  delay(250);
  _serial.println("Turn right");
}
