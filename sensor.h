#include <Arduino.h>

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
  public:
    Sensor(void);
    ~Sensor(void);
    uint8_t read(void);

    static const uint8_t sensor_nothing = 0;
    static const uint8_t sensor_left = 1;
    static const uint8_t sensor_middle = 2;
    static const uint8_t sensor_right = 4;
    static const uint8_t sensor_all = 7;
  private:
    const uint8_t pin_left = A1;
    const uint8_t pin_middle = A2;
    const uint8_t pin_right = A3;
    const uint16_t threshold = 800;
};


#endif
