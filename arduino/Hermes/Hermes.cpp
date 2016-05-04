#include "Arduino.h"
#include "Hermes.h"

Hermes::Hermes()
  // RBD::SerialManager constructor()
  : _serial()
  , _motors(_serial)
{}


void Hermes::start() {
  _serial.start();
}

void Hermes::listen() {
  if (_serial.onReceive()) {
    switch (_translateSerialCommand()) {
      case FORWARD: _motors.forward(); break;
      case BACKWARD: _motors.backward(); break;
      case STOP: _motors.stop(); break;
      case TURN_LEFT: _motors.turnLeft(); break;
      case TURN_RIGHT: _motors.turnRight(); break;
      case NOOP:
      default: _serial.println("Unknown command. Noop.");
    }
  }
}

uint8_t Hermes::_translateSerialCommand() {
    if (_serial.isCmd("forward") || _serial.isCmd("f")) return FORWARD;
    else if (_serial.isCmd("backward") || _serial.isCmd("b")) return BACKWARD;
    else if (_serial.isCmd("stop") || _serial.isCmd("s")) return STOP;
    else if (_serial.isCmd("turnleft") || _serial.isCmd("l")) return TURN_LEFT;
    else if (_serial.isCmd("turnright") || _serial.isCmd("r")) return TURN_RIGHT;
    else return NOOP;
}
