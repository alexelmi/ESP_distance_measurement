// define Pins
const int ledPin = 5;
const int pinTrigger = 13;
const int pinEcho = 12;
const int BuzzerPin = 0;
int waiting = 0;
long duration = 0;
long distanceCM = 0;

void setup()
{
  Serial.begin (115200);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
}

void loop()
{
  digitalWrite(pinTrigger, LOW);
  delay(5);
  digitalWrite(pinTrigger, HIGH);
  delay(10);
  digitalWrite(pinTrigger, LOW);
  duration = pulseIn(pinEcho, HIGH);
  distanceCM = (duration / 2) * 0.03432;
  if (distanceCM >= 500)
  {
    waiting = 1100;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 500) && distanceCM >= 400) {
    waiting = 1000;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 399) && distanceCM >= 300) {
    waiting = 800;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 299) && distanceCM >= 200) {
    waiting = 700;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 199) && distanceCM >= 100) {
    waiting = 500;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 99) && distanceCM >= 80) {
    waiting = 400;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 79) && distanceCM >= 60) {
    waiting = 300;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 59) && distanceCM >= 40) {
    waiting = 200;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 39) && distanceCM >= 20) {
    waiting = 100;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if ((distanceCM <= 19) && distanceCM >= 10) {
    waiting = 50;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  else if (distanceCM <= 9) {
    waiting = 0;
    Serial.print(distanceCM);
    Serial.println(" cm");
  }
  digitalWrite(ledPin, HIGH);   //turn LED on
  digitalWrite (BuzzerPin, HIGH);  //turn BuzzerPin on
  delay(waiting);
  digitalWrite(ledPin, LOW);    //turn LED off
  digitalWrite (BuzzerPin, LOW);   //turn BuzzerPin off
  delay(waiting);
}
