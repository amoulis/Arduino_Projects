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
  t_sensor sensor1, sensor2;
  
  sensor1.led = PIN_LED_1;
  sensor1.sensor = PIN_SENSOR_1;
  sensor1.activated = 0;
  
  sensor2.led = PIN_LED_2;
  sensor2.sensor = PIN_SENSOR_2;
  sensor2.activated = 0;
  // Light up LED on detection
  light_up_led(sensor1);
  light_up_led(sensor2);
  
  // Algo
  
  if(isDetected(sensor1.sensor))
  {
    if(sensor2.activated == 0)
      sensor1.activated = 1;
    else if(sensor2.activated == 1)
    {
      sensor2.activated = 0;
      inside--;
      out++;
    }  
  }
  else if (isDetected(sensor2.sensor))
  {
    if(sensor1.activated == 0)
      sensor1.activated = 1;
    else if(sensor1.activated == 1)
    {
      sensor1.activated = 0;
      inside++;
      in++;
    }  
  
  }
  
  if(inside < 0)
    inside = 0;
    
  Serial.println("\n People Inside: ");
  Serial.println(inside);
  Serial.println("\n nb of enters: ");
  Serial.println(in);
  Serial.println("\n nb left: ");
  Serial.println(out);
  
  delay(1000);
  
}


