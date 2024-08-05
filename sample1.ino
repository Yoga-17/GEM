#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
#include "functions.h"

const char *ssid = "Vivo y73";
const char *password = "11111111";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");
  while (WiFi.status() != WL_CONNECTED) {delay(500); Serial.print(".");}
  Serial.println("");
  Serial.println("ESP8266 Webpage");
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/jewel.php"/led)
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
      if (digitalRead(D1)==1){
    digitalWrite(D2,LOW);
    }
  else{
    digitalWrite(D2,HIGH);
    }
  if (digitalRead(D5)==1){
    digitalWrite(D4,LOW);
    }
  else{
    digitalWrite(D4,HIGH);
    }
  if (digitalRead(D6)==1){
    digitalWrite(D7,LOW);
    }
  else{
    digitalWrite(D7,HIGH);
    }
}
