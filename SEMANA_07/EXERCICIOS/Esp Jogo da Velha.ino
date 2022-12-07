
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

int winner = 99;

const char* ssid = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

//Your Domain name with URL path or IP address with path
String serverName = "https://43u6xt-3071.preview.csb.app/api/v1/tags";
// String serverName = "http://127.0.0.1:3061/";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 1000;

void setup() {
  Serial.begin(115200); 

  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + "?temperature=24.37";
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      StaticJsonDocument<200> doc;


      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        deserializeJson(doc, payload);
        winner = int(doc["vencedor"]);
        Serial.println(winner);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }

      if (winner == 0) {
        digitalWrite(9 , HIGH);
        digitalWrite(3 , LOW);
      }

      else if (winner == 1) {
        digitalWrite(3 , HIGH);
        digitalWrite(9 , LOW);
      }


      else {
        digitalWrite(9 , LOW);
        digitalWrite(3 , LOW);
      }


      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}