#include "RBD_SerialManager.h"
#include "Hermes.h"

RBD::SerialManager ser;
Hermes herm;

void setup()
{
  ser.start();
}

void loop()
{
  if (ser.onReceive()) {
    if (ser.isCmd("forward") || ser.isCmd("f")) {
      herm.forward();
      ser.println("forward!");
    } else if (ser.isCmd("reverse") || ser.isCmd("b")) {
      herm.reverse();
      ser.println("reverse!");
    } else if (ser.isCmd("turnleft") || ser.isCmd("l")) {
      herm.turnLeft();
      ser.println("turn left!");
    } else if (ser.isCmd("turnright") || ser.isCmd("r")) {
      herm.turnRight();
      ser.println("turn right!");
    } else {
      herm.stop();
      ser.println("stop!");
    }
  }
}
