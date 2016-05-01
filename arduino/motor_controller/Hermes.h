#ifndef Hermes_h
#define Hermes_h

#include "RBD_Motor.h"

// Motor front left
#define MOTOR_FL_PWM 11
#define MOTOR_FL_FORWARD 12
#define MOTOR_FL_REVERSE 13
// Motor front right
#define MOTOR_FR_PWM 9
#define MOTOR_FR_FORWARD 4
#define MOTOR_FR_REVERSE 5
// Motor rear left
#define MOTOR_RL_PWM 10
#define MOTOR_RL_FORWARD 7
#define MOTOR_RL_REVERSE 8
// Motor rear right
#define MOTOR_RR_PWM 6
#define MOTOR_RR_FORWARD 2
#define MOTOR_RR_REVERSE 3

class Hermes
{
  public:
    Hermes();
    void forward();
    void reverse();
    void turnLeft();
    void turnRight();
    void stop();
  private:
    void _helpTurnLeft();
    void _helpTurnRight();
    RBD::Motor _motorFrontL;
    RBD::Motor _motorFrontR;
    RBD::Motor _motorRearL;
    RBD::Motor _motorRearR;
};

#endif
