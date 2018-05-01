// sketch_06_08_ESP32_sleep_pin

gpio_num_t wakeupPin = GPIO_NUM_33;

void setup()
{
  Serial.begin(9600);
  Serial.println("I'm awake");
  delay(2000);

  pinMode(wakeupPin, INPUT_PULLUP);
  esp_sleep_enable_ext0_wakeup(wakeupPin, LOW); // wakeup when goes LOW
  Serial.println("I'm going to sleep now");
  esp_deep_sleep_start();
  Serial.println("This will never be printed, wake goes to setup");
}

void loop(){
  //This will never be reached
}
