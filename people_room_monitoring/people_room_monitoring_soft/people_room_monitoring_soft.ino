#include <Arduino.h>
#include "people_room_monitoring.h"

  int enter = 0, inside = 0, out = 0;
  t_sensor sensor1, sensor2;
  int stateChanged = 0;
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
  
  sensor1.led = PIN_LED_1;
  sensor1.sensor = PIN_SENSOR_1;
  sensor1.activated = 0;
  
  sensor2.led = PIN_LED_2;
  sensor2.sensor = PIN_SENSOR_2;
  sensor2.activated = 0;
}

void loop()
{

  
  char data[1000];
  char data_prev[1000];
  
  // Light up LED on detection
  light_up_led(sensor1);
  light_up_led(sensor2);
  
  // Algo
  
  if(isDetected(sensor1.sensor) == true)
  {
    if(sensor2.activated == 0)
    {  
      sensor1.activated = 1;
    }else if(sensor2.activated == 1)
    {
      sensor2.activated = 0;
      inside--;
      out++;
      stateChanged = 1;
    }  
  }
  if (isDetected(sensor2.sensor) == true)
  {
    if(sensor1.activated == 0){
      sensor2.activated = 1;  
    }
    else if(sensor1.activated == 1)
    {
      sensor1.activated = 0;
      inside++;
      enter++;
      stateChanged = 1;
    }  
  
  }
  
  if(inside < 0)
    inside = 0;
  
  if (stateChanged == 1)
  {
    sprintf(data, "enters : %d, inside the room: %d, left: %d \n", enter, inside, out);
    Serial.println(data);
    stateChanged = 0;
  }
  //delay(100);
  
}


