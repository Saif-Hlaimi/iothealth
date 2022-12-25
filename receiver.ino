#include <SPI.h>
#include <LoRa.h>
#include <FirebaseESP32.h>
#include<Firebase.h>
#include <WiFi.h>
#include <SD.h>

#define FIREBASE_HOST "your firebase host code"
#define FIREBASE_AUTH "your firebase auth code"
#define WIFI_SSD "you wifi ssd"
#define WIFI_PASSWORD "your wifi password"

#define ss 15
#define rst 4
#define dio0 17

FirebaseData Data;

String heartrate; 



void setup() {

  Serial.begin(921600);
  while (!Serial);
  delay(500);
  Serial.println("LoRa Receiver");
 LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

   // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSD);
  WiFi.begin(WIFI_SSD, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);


}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    
      String LoRaData = LoRa.readString();

      while (LoRa.available()){
        Serial.print((char)LoRa.read());
      }

       
      
      
      String Nom="Nom",name ="your name",HEARTBEAT="HEARTBEAT";

      Firebase.setString(Data,"/valeur/Nom",name);
      Firebase.setString(Data,"/valeur/HEARTBEAT", LoRaData.substring(0, LoRaData.indexOf('/')));


  }
}