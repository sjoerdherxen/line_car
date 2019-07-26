#include <Arduino.h>

#include "drive.h"
#include "sensor.h"

Drive drive;
Sensor sensor;

const uint16_t finish_width = 2000;

void setup() {
  
}

void loop() {
  switch(sensor.read()){
    case Sensor::sensor_nothing:
      nothing();
      break;
      
    case Sensor::sensor_left | Sensor::sensor_right:
      wtf();
      break;
      
    case Sensor::sensor_left:
    case Sensor::sensor_left | Sensor::sensor_middle:
      turn_left();
      break;
      
    case Sensor::sensor_middle:
      forward();
      break;
      
    case Sensor::sensor_right:
    case Sensor::sensor_right | Sensor::sensor_middle:
      turn_right();
      break;
      
    case Sensor::sensor_all:
      forward_all();
      break;

    default:
      nothing();
  }
}

void forward() {
  drive.forward();
  while (sensor.read() == Sensor::sensor_middle) {
    delay(1);  
  }
  drive.stop();
}

void turn_left() {
  drive.turn_left();
  while (sensor.read() == Sensor::sensor_middle | Sensor::sensor_left || sensor.read() == Sensor::sensor_left) {
    delay(1);  
  }
  drive.stop();
}

void turn_right() {
  drive.turn_right();
  while (sensor.read() == Sensor::sensor_middle | Sensor::sensor_right || sensor.read() == Sensor::sensor_right) {
    delay(1);  
  }
  drive.stop();
}

void wtf() {
  drive.backward();
  while (sensor.read() == Sensor::sensor_left | Sensor::sensor_right) {
    delay(1);  
  }
  drive.stop();
}

void nothing() {
  drive.stop();
  while (sensor.read() == Sensor::sensor_nothing) {
    delay(1);  
  }
  drive.stop();
}

bool forward_all() {
  uint16_t width = 0;
  drive.forward();
  
  while (sensor.read() == Sensor::sensor_all) {
    delay(1);
    if (width > finish_width) {
      drive.stop();
      return true;
    }
    width++;
  }
  
  drive.stop();
  return false;
}
