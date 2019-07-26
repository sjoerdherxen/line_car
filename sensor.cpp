#include "sensor.h"

Sensor::Sensor(void) {
  pinMode(pin_left, INPUT);
  pinMode(pin_middle, INPUT);
  pinMode(pin_right, INPUT);
}

Sensor::~Sensor(void) { }

uint8_t Sensor::read(void) {
  uint8_t result = sensor_nothing;

  if (analogRead(pin_left) > threshold) {
    result |= sensor_left;
  }

  if (analogRead(pin_middle) > threshold) {
    result |= sensor_middle;
  }

  if (analogRead(pin_right) > threshold) {
    result |= sensor_right;
  }
  
  return result;
}
