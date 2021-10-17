// Thanks to https://www.smarthome-tricks.de/esp8266/esp8266-blinkende-led/

const int ledPin = 5;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
