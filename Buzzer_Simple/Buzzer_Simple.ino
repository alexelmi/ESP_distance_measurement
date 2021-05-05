// Thanks to https://diyi0t.com/active-passive-BuzzerPin-arduino-esp8266-esp32/

int BuzzerPin = 0;
int peeping = 500;
void setup() {
  pinMode (BuzzerPin, OUTPUT);
}

void loop() {
  digitalWrite (BuzzerPin, HIGH); //turn BuzzerPin on
  delay(peeping);
  digitalWrite (BuzzerPin, LOW);  //turn BuzzerPin off
  delay(peeping);
}