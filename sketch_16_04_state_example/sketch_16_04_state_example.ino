// sketch_16_04_state_example

const int ledPin = 13;
const int switchPin = 4; // push switch between pin 4 and GND
const int blinkDelay = 500;

enum {OFF, ON, BLINK_ON, BLINK_OFF} mode;

long lastTime = 0; // the time the LED blinked on or off

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  mode = OFF;
}

void loop() 
{
  if (mode == OFF)
  {
    handleOFF();
  }
  else if (mode == ON)
  {
    handleON();
  }
  else if (mode == BLINK_ON)
  {
    handleBLINK_ON();
  }
  else if (mode == BLINK_OFF)
  {
    handleBLINK_OFF();
  }
}

void handleOFF()
{
  if (switchPressed())
  {
    digitalWrite(ledPin, HIGH);
    mode = ON;
  }
}

void handleON()
{
  if (switchPressed()) 
  {
    lastTime = millis();
    mode = BLINK_ON;
  }
}

void handleBLINK_ON()
{
  if (switchPressed())
  {
    digitalWrite(ledPin, LOW);
    mode = OFF;
  }
  long now = millis();
  if (now > lastTime + blinkDelay)
  {
    digitalWrite(ledPin, LOW);
    lastTime = now;
    mode = BLINK_OFF;
  }
}

void handleBLINK_OFF()
{
  if (switchPressed())
  {
    mode = OFF;
  }
  long now = millis();
  if (now > lastTime + blinkDelay)
  {
    digitalWrite(ledPin, HIGH);
    lastTime = now;
    mode = BLINK_ON;
  }
}

boolean switchPressed()
{
  if (digitalRead(switchPin) == LOW)
  {
    delay(100); // debounce
    return true;
  }
  return false;
}

