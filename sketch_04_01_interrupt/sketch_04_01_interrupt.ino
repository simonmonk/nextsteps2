// sketch 04_01_interrupts

const int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, stuffHapenned, FALLING);
}

void loop()
{
}

void stuffHapenned()
{
  digitalWrite(ledPin, HIGH);
}
