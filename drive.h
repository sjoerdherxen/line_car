#include "AFMotor.h"
#include <Arduino.h>

#ifndef DRIVE_H
#define DRIVE_H

class Drive
{
  public:
    Drive(void);
    ~Drive(void);
    void forward(void);
    void backward(void);
    void turn_left(void);
    void turn_right(void);
    void stop(void);
  private:
    AF_DCMotor motor_left = 3;
    AF_DCMotor motor_right = 4;
};


#endif
