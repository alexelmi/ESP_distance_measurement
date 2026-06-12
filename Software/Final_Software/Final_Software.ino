// Ultrasonic distance meter for the WeMos D1 mini (ESP8266).
// A closer object makes the LED blink and the buzzer beep faster; when nothing
// is in range the device stays quiet.
//
// Pin mapping verified against the KiCad netlist (Hardware/KiCad_Files):
//   Trigger -> GPIO13 (D7)            Echo                  -> GPIO12 (D6)
//   LED     -> GPIO5  (D1), via R1    Buzzer (via Q1 + R2)  -> GPIO0  (D3)
//
// The distance/interval logic lives in distance_logic.h so it can be unit
// tested on a PC (see ../Tests).

#include "distance_logic.h"

const int pinTrigger = 13;
const int pinEcho    = 12;
const int ledPin     = 5;
const int buzzerPin  = 0;

// pulseIn() timeout in microseconds. 30 ms ~= 5 m round trip; this caps the
// loop time when there is no echo instead of blocking for a full second.
const unsigned long ECHO_TIMEOUT_US = 30000UL;

void setup()
{
  Serial.begin(115200);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(pinTrigger, LOW);
}

// Fire one 10 us trigger pulse and return the echo width in microseconds.
// HC-SR04 expects a 10 us HIGH pulse on TRIG; the previous version used
// delay() (milliseconds) which was 1000x too long.
long measureEchoUs()
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  return pulseIn(pinEcho, HIGH, ECHO_TIMEOUT_US);
}

// One blink/beep cycle. waitMs == 0 means "very close" -> solid tone/light.
void signalDistance(int waitMs)
{
  if (waitMs <= 0) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    return;
  }
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(waitMs);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(waitMs);
}

void loop()
{
  long distanceCM = echoToDistanceCm(measureEchoUs());

  if (distanceCM == NO_MEASUREMENT) {
    Serial.println("No reading");
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);                 // idle quietly, then measure again
    return;
  }

  Serial.print(distanceCM);
  Serial.println(" cm");
  signalDistance(distanceToWaitingMs(distanceCM));
}
