#include "Arduino.h"
#include "Hermes.h"

Hermes::Hermes()
  // RBD::SerialManager constructor()
  : _serial()
  , _motors()
{}


void Hermes::start() {
  _serial.start();
}

void Hermes::listen() {
  if (_serial.onReceive()) {
    if (_serial.isCmd("forward") || _serial.isCmd("f")) {
      _motors.forward();
      _serial.println("Forward");
    } else if (_serial.isCmd("reverse") || _serial.isCmd("b")) {
      _motors.reverse();
      _serial.println("Reverse");
    } else if (_serial.isCmd("turnleft") || _serial.isCmd("l")) {
      _motors.turnLeft();
      _serial.println("Turn left");
    } else if (_serial.isCmd("turnright") || _serial.isCmd("r")) {
      _motors.turnRight();
      _serial.println("Turn right");
    } else {
      _motors.stop();
      _serial.println("Stop");
    }
  }
}
