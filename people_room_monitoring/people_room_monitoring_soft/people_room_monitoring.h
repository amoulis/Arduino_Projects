#ifndef PEOPLE_ROOM_MONITORING_H
#define PEOPLE_ROOM_MONITORING_H

#define PIN_SENSOR_1 2
#define PIN_SENSOR_2 4

#define PIN_LED_1 13
#define PIN_LED_2 12

struct tsensor
{
  int led;
  int sensor;
};

typedef tsensor t_sensor;

void light_up_led(t_sensor sens);
bool isDetected(int pinsensor);

#endif
