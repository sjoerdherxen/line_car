#include "drive.h"

Drive::Drive(void) {

  motor_left.setSpeed(200);
  motor_right.setSpeed(200);
}

Drive::~Drive(void) { }

void Drive::forward(void) {
  stop();
  motor_left.run(FORWARD);
  motor_right.run(FORWARD);
}


void Drive::backward(void) {
  stop();
  motor_left.run(BACKWARD);
  motor_right.run(BACKWARD);
}

void Drive::turn_left(void) {
  stop();
  motor_left.run(BACKWARD);
  motor_right.run(FORWARD);

}

void Drive::turn_right(void) {
  stop();
  motor_left.run(FORWARD);
  motor_right.run(BACKWARD);

}

void Drive::stop(void) {
  motor_left.run(RELEASE);
  motor_right.run(RELEASE);
  delay(100);
}
