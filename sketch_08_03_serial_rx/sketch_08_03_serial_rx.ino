// sketch_08_03_serial_rx

const int dataPin = 5;
const int clockPin = 6;

byte x = 0;

void setup() 
{
  pinMode(dataPin, INPUT_PULLUP); // pullup stops floating inputs
  pinMode(clockPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  byte x = 0;
  for (int i = 0; i < 8; i++)
  {
    // wait for clock to go high
    //Serial.println(i);
    while (digitalRead(clockPin) == LOW) {};
    // read the data pin
    x = x << 1;                 // shift all the bits left one place
    x += digitalRead(dataPin);  // add the new bit
    // wait for clock to go low to be ready for next bit
    while (digitalRead(clockPin) == HIGH) {};
  }
  Serial.println(x);
}

