//const int ledPin = D0;    // NodeMCU built-in LED
const int ledPin = D4;    // Wemos D1 mini buil-in LED

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);

}
