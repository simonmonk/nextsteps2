// sketch_14_03_web_request

// JSON web request to openweathermap.org
// {"coord":{"lon":-0.13,"lat":51.51},"weather":[{"id":521,"main":"Rain","description":"shower rain","icon":"09d"}],
// "base":"stations","main":{"temp":286.85,"pressure":1016,"humidity":47,"temp_min":286.15,"temp_max":288.15},
// "visibility":10000,"wind":{"speed":5.7,"deg":250},
// "clouds":{"all":20},"dt":1524750600,"sys":{"type":1,"id":5091,"message":0.0095,"country":"GB","sunrise":1524717668,"sunset":1524770185},
// "id":2643743,"name":"London","cod":200}


#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>

byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

EthernetClient client;

void setup() 
{
  Serial.begin(9600);
  while (!Serial){}; // for Leonardo compatability

  if (! Ethernet.begin(mac)) 
  {
    Serial.println(F("Could not connect to network"));
  }
  else 
  {
    Serial.println(F("Connected to network"));
  }
  delay(1000);
  doWebRequest();
}

void loop() 
{
}

void doWebRequest()
{
  if (client.connect("api.openweathermap.org", 80))
  {
    //Serial.println(F("Connected to server"));
    client.println(F("GET /data/2.5/weather?q=Manchester,uk&APPID=your_key_goes_here HTTP/1.0"));
    client.println(F("Connection: close"));
    client.println(); // end of request
    if (client.connected() && statusOK() && skipedHeaders())
    {
      parseAndPrintWeather();
      client.stop();
    }
  } 
}

void parseAndPrintWeather()
{
  //Serial.println("Parsing");
  // Use arduinojson.org/assistant to compute the capacity.
  const size_t capacity = 1024;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& root = jsonBuffer.parseObject(client);
  if (!root.success()) 
  {
    Serial.println(F("Parsing failed"));
    return;
  }
  JsonObject& weather = root["weather"][0];
  Serial.println(weather["description"].as<char*>());
  //Serial.println("Finished Parsing");
}

boolean statusOK() 
{
  char status[64] = {0}; // big enough for header
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return false;
  }
  return true;
}

boolean skipedHeaders() 
{
  //Serial.println("skipping headers");
  char endOfHeaders[] = "\r\n\r\n";
  return (client.find(endOfHeaders));
}

