// sketch_08_02_serial_tx

const int dataPin = 5;
const int clockPin = 6;

byte x = 0;

void setup() 
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  if (x > 100)
  {
    x = 0;
  }
  sendByte(x);
  x++;
  delay(1000);
}

void sendByte(byte b)
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(dataPin, bitRead(b, 7-i)); // set the data high or low
    delay(1);                     // delay for 1ms
    digitalWrite(clockPin, HIGH); // start of clock pulse
    delay(1);
    digitalWrite(clockPin, LOW); 
    delay(1);    
  }
}

