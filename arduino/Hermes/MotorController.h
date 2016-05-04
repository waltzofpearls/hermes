#ifndef MotorController_h
#define MotorController_h

#include "RBD_Motor.h"
#include "RBD_SerialManager.h"

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

#define NOOP 0
#define FORWARD 1
#define BACKWARD 2
#define STOP 3
#define TURN_LEFT 4
#define TURN_RIGHT 5


class MotorController
{
  public:
    MotorController(RBD::SerialManager);
    void forward();
    void backward();
    void stop();
    void turnLeft();
    void turnRight();
  private:
    RBD::Motor _motorFrontL;
    RBD::Motor _motorFrontR;
    RBD::Motor _motorRearL;
    RBD::Motor _motorRearR;
    RBD::SerialManager _serial;
    void _helpTurnLeft();
    void _helpTurnRight();
};

#endif
