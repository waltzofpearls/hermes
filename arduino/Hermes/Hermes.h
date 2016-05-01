#ifndef Hermes_h
#define Hermes_h

#include "RBD_SerialManager.h"
#include "MotorController.h"

class Hermes
{
  public:
    Hermes();
    void start();
    void listen();
  private:
    RBD::SerialManager _serial;
    MotorController _motors;
};

#endif
