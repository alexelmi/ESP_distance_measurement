//thanks to https://www.smarthome-tricks.de/esp8266/mit-dem-ultraschallsensor-entfernungen-messen/

// Pins must match the PCB: TRIG -> GPIO13 (D7), ECHO -> GPIO12 (D6).
// (The original sketch used GPIO15 for ECHO, which is not wired to the sensor
// on this board - see Hardware/KiCad_Files netlist.)
const int pinTrigger = 13;
const int pinEcho = 12;

long duration = 0;
long distanceCM = 0;

void setup()
{
  Serial.begin (115200);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinTrigger, LOW);
}

void loop()
{
  // HC-SR04 trigger: a 10 microsecond HIGH pulse (not milliseconds!).
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);

  duration = pulseIn(pinEcho, HIGH, 30000UL);  // 30 ms timeout (~5 m)
  distanceCM = (duration / 2.0) * 0.03432;
  if (duration == 0 || distanceCM >= 500 || distanceCM <= 0)
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
