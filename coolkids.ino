#include <ESP8266WiFi.h>            
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);  



void setup() {

Serial.begin(115200);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D7,OUTPUT);

                                             //Open Serial connection
WiFi.begin("Galaxy M124FF0", "09876543");                          //Connect to the WiFi network

while (WiFi.status() != WL_CONNECTED) {    //Wait for connection

delay(500);
Serial.println("Waiting to connect…");

}

Serial.print("IP address: ");
Serial.println(WiFi.localIP());  //Print the local IP

  
server.on("/", []() {
 bool ismissing1;
 bool ismissing2;
 bool ismissing3;
 if (digitalRead(D1)==1){
  digitalWrite(D2,LOW);
  ismissing1=false;
    }
  else{
    digitalWrite(D2,HIGH);
    ismissing1=true;
    }
  if (digitalRead(D5)==1){
    digitalWrite(D4,LOW);
    ismissing2=false;
    }
  else{
    digitalWrite(D4,HIGH);
    ismissing2=true;
    }
  if (digitalRead(D6)==1){
    digitalWrite(D7,LOW);
    ismissing3=false;
    }
  else{
    digitalWrite(D7,HIGH);
    ismissing3=true;
    }//Define the handling function for root path (HTML message)
Serial.println(ismissing1);
if(ismissing1){
  server.send(200, "text/html", "RING 1 IS MISSING");}
else{
  server.send(200, "text/html", "RING IS NOT MISSING");
  }  

});
server.enableCORS(true);
server.begin(); //Start the server

Serial.println("Server listening");
}

void loop() {
server.handleClient(); //Handling of incoming requests
}
