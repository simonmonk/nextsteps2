
// sketch_14_05_esp32_server
// https://github.com/Pedroalbuquerque/ESP32WebServer

#include <WiFiClient.h>
#include <ESP32WebServer.h>
#include <WiFi.h>
#include <ESPmDNS.h>

const char* ssid = "";
const char* password = "";
const int relayPin = 22;

ESP32WebServer server(80);

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  connectToWiFi();
  server.on("/", HTTP_GET, handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void connectToWiFi() {
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

void handleRoot() {
  Serial.println("Got a Request");
  if (server.arg(0)[0] == '1') {
    digitalWrite(relayPin, HIGH);
  }
  else {
    digitalWrite(relayPin, LOW);
  }
  String msg = "";
  msg += "<html><body>\n";
  msg += "<h1>Relay Remote</h1>";
  msg += "<h2><a href='?a=1'/>On</a></h2>";
  msg += "<h2><a href='?a=0'/>Off</a></h2>";
  msg += "</body></html>";
  
  server.send(200, "text/html", msg);
}
