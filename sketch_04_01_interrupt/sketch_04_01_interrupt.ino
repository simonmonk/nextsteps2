// sketch 04_01_interrupts

const int ledPin = 13;
const int interruptPin = 2;

void setup()
{
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), stuffHapenned, FALLING);
}

void loop()
{
}

void stuffHapenned()
{
  digitalWrite(ledPin, HIGH);
}
