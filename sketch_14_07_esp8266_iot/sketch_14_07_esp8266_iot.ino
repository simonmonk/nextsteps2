// sketch_14_07_iot

#include <ESP8266WiFi.h>

const long logPeriod = 30000; //ms
const char thingName[] = "next_steps_temp"; // change this to avoid interference with other readers

const char* ssid = "";   // your network name
const char* password = ""; // your network passwords
const int sensorPin = A0;

long lastSendTime = -logPeriod; // so we don't wait for first send
WiFiClient client;

void setup() 
{
  Serial.begin(9600);
  connectToWiFi();
}

void loop() 
{
  long now = millis();
  if (now > lastSendTime + logPeriod)
  {
    lastSendTime = now;
    float temp = readTemp();
    Serial.println(temp);
    sendTemp(temp);
  }
}

void sendTemp(float temp)
{
  if (!client.connect("dweet.io", 80)) 
  {
    Serial.println("Connection failed");
    return;
  }
  Serial.println("Connected");
      
    client.print("GET /dweet/for/");
    client.print(thingName);
    client.print("?temp=");
    client.print(temp);
    client.print(" HTTP/1.1\r\nHost: dweet.io\r\nConnection: close\r\n\r\n");

    Serial.println("Response:");
    while (client.connected())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
        Serial.println(line);
      }
    }
    client.stop();
    Serial.println("\n[Disconnected]");
}

float readTemp()
{
  int reading = analogRead(sensorPin);
  float volts = reading * 3.3 / 1023;
  float degC = volts * 100 - 50;
  // float degF = degC * 9.0 / 5.0 + 32.0;
  return degC;
}

void connectToWiFi() 
{
  Serial.print("\n\nConnecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


