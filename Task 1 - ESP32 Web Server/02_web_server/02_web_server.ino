#include <WiFi.h>
#include <WebServer.h>
#include "secrets.h"   // WIFI_SSID and WIFI_PASSWORD live here (not tracked by git)

const char* ssid     = WIFI_SSID;
const char* password = WIFI_PASSWORD;

WebServer server(80);   // HTTP port 80

void handleRoot() {
  server.send(200, "text/plain", "Hello from my ESP32! Wireless text is working.");
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Page not found");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! Open this in your browser: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();   // must be called constantly
}