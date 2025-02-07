#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define MQ2pin (0)
 
float sensorValue;  
float gasLevel=300;
bool ledState = false;

const char* ssid = "FormerTopol";
const char* password = "sasa2020";

//const char* mqtt_server = "192.168.1.2";
const char* mqtt_server = "broker.hivemq.com";


WiFiClient esp8266device;
PubSubClient client(esp8266device);


void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
 // Serial.println();
 // Serial.print("Connecting to ");
 // Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   Serial.print(".");
  }
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messagein;
  if (topic=="room1/mq2/level"){
     for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messagein += (char)message[i];
  }  
  gasLevel=messagein.toFloat();
   Serial.print("new Gas level: ");
    Serial.print(gasLevel);
    Serial.println();
  }
 
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("device1")) {
      Serial.println("connected");
      client.subscribe("room1/mq2/danger");
      client.subscribe("room1/mq2/level");
      client.subscribe("room1/mq2");
    } else {
      delay(5000);
    }
  }
}


void setup() {
  
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  
  setup_wifi();
  Serial.println("Gas sensor warming up!");
  delay(20000);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {
  sensorValue = analogRead(MQ2pin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

   if (!client.connected()) {
    reconnect();
  }
    if(!client.loop())
    client.connect("device1");
    float gas_value=sensorValue;
       char g [8];
       dtostrf(gas_value,6,2,g);  
              
   client.publish("room1/mq2",g);
   delay(2000);  
   
  if(sensorValue > gasLevel)
  {
      Serial.print(" | Smoke detected!");
      ledState = true;
      char g [8];
      dtostrf(sensorValue,6,2,g);  
      client.publish("room1/mq2/danger",g);
      //delay(2000);
  }
  digitalWrite(4, ledState ? HIGH : LOW);
  if (sensorValue < gasLevel) {
    ledState = false;  // Store LED state as OFF
  }
  Serial.println("");
   delay(1000);
} 
