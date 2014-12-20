#include <Arduino.h>
#include "people_room_monitoring.h"

bool isDetected(int pinsensor)
{
  if (digitalRead(pinsensor) == HIGH) 
    return false;
  else
    Serial.println("LOW\n");
    return true;
}

void light_up_led(t_sensor sens)
{
  if(isDetected(sens.sensor))
    digitalWrite(sens.led, HIGH);
  else
    digitalWrite(sens.led, LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_SENSOR_1, INPUT);
  pinMode(PIN_LED_1, OUTPUT);     
  pinMode(PIN_SENSOR_2, INPUT);
  pinMode(PIN_LED_2, OUTPUT);   
  
}

void loop()
{
  int in = 0, inside = 0, out = 0;
  int S1_act = 0, S2_act = 0;
  t_sensor sensor1, sensor2;
  
  sensor1.led = PIN_LED_1;
  sensor1.sensor = PIN_SENSOR_1;
  
  sensor2.led = PIN_LED_2;
  sensor2.sensor = PIN_SENSOR_2;
  // Light up LED on detection
  light_up_led(sensor1);
  light_up_led(sensor2);
  
  // Algo
}


