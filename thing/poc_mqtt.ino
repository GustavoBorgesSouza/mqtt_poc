#include <PubSubClient.h>
#include <WiFi.h>
#include "config.h"

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";

WiFiClient espClient;
PubSubClient client(espClient);

int lightPin = 18;
int light = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_wifi();
  client.setServer(MQTT_SERVER, 1883);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  // Reconnect Wi-Fi if it disconnects
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected; attempting reconnect");
    setup_wifi();
  }

  // Reconnect to MQTT broker if not connected
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    // Temperature in Celsius
    light = analogRead(lightPin);

    // Convert the value to a char array
    char lightString[8];
    dtostrf(light, 1, 2, lightString);
    Serial.print("light: ");
    Serial.println(light);
    Serial.println(lightString);
    client.publish("esp32/light", lightString);
  }
}