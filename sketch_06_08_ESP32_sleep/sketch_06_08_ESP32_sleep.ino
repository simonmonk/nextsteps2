// sketch_06_08_ESP32_sleep

void setup()
{
  Serial.begin(9600);
  Serial.println("I'm awake");
  delay(10000);
  
  esp_sleep_enable_timer_wakeup(20e6);
  Serial.println("I'm going to sleep now");
  esp_deep_sleep_start();
  Serial.println("This will never be printed, wake goes to setup");
}

void loop(){
  //This will never be reached
}
