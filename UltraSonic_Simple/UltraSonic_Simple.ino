//thanks to https://www.smarthome-tricks.de/esp8266/mit-dem-ultraschallsensor-entfernungen-messen/

const int pinTrigger=D7;
const int pinEcho=D6; 
 
long duration=0;
long distanceCM=0; 
 
void setup()
{
  Serial.begin (115200);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
}
 
void loop()
{
  digitalWrite(pinTrigger, LOW);
  delay(5);
  digitalWrite(pinTrigger, HIGH);
  delay(10);
  digitalWrite(pinTrigger, LOW);
 
  duration = pulseIn(pinEcho, HIGH);
  distanceCM = (duration/2) * 0.03432;
  if (distanceCM >= 500 || distanceCM <= 0)
  {
    Serial.println("Kein Messwert");
  }
  else
  {
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  delay(1000);
}