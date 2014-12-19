/********************************************
A very very simple program that light up a LED
when the distance senor is detecting something

Hardware:
- Arduino Uno
- LED
- Pololu SHARP GP2Y0D805Z0F

Adrien Moulis 19/12/2014
*********************************************/

#define PIN_OUT_SENSOR 2
#define PIN_LED 13

bool isDetected()
{
  if (digitalRead(PIN_OUT_SENSOR) == HIGH) 
    return false;
  else
    Serial.println("LOW\n");
    return true;
}


void setup()
{
  Serial.begin(9600);
  pinMode(PIN_OUT_SENSOR, INPUT);
  pinMode(PIN_LED, OUTPUT);     
  
}

void loop()
{
  // get sensor value
  
 // int state = digitalRead(PIN_OUT_SENSOR);
  
  if(isDetected())
    digitalWrite(PIN_LED, HIGH);
  else
    digitalWrite(PIN_LED, LOW);
  
}
