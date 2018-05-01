// sketch_06_07_ESP8266_sleep

#include <ESP8266WiFi.h>

char* ssid     = "your_wireless_network";
char* password = "your_password";

void setup(){
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
  }
  Serial.println("I'm awake");
  delay(10000);
  
  Serial.println("I'm going to sleep now");
  ESP.deepSleep(20e6);
  Serial.println("This will never be printed, wake goes to setup");
}

void loop(){
  //This will never be reached
}
