#include <WiFi.h>
#include <WebServer.h>
#include "secrets.h"   // WIFI_SSID and WIFI_PASSWORD live here (not tracked by git)

const char* ssid     = WIFI_SSID;
const char* password = WIFI_PASSWORD;

WebServer server(80);

// Simulated readings (replace with real sensor code later)
float readTemperature() { return 24.0 + random(-20, 20) / 10.0; }   // about 22 to 26 C
float readHumidity()    { return 60.0 + random(-50, 50) / 10.0; }   // about 55 to 65 %
int   readCO2()         { return 450 + random(-30, 80); }           // about 420 to 530 ppm

void handleRoot() {
  float t = readTemperature();
  float h = readHumidity();
  int co2 = readCO2();

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<meta http-equiv='refresh' content='3'>";   // reload every 3 seconds
  html += "<title>Grain Monitor</title>";
  html += "<style>body{font-family:Arial;text-align:center;margin-top:40px;}";
  html += ".card{display:inline-block;margin:10px;padding:20px 30px;border-radius:10px;background:#eef4fa;}";
  html += "h1{color:#1F4E79;} .v{font-size:2em;font-weight:bold;}</style></head><body>";
  html += "<h1>Grain Storage Monitor (Demo)</h1>";
  html += "<div class='card'>Temperature<div class='v'>" + String(t, 1) + " &deg;C</div></div>";
  html += "<div class='card'>Humidity<div class='v'>" + String(h, 1) + " %</div></div>";
  html += "<div class='card'>CO2<div class='v'>" + String(co2) + " ppm</div></div>";
  html += "<p>Uptime: " + String(millis() / 1000) + " s | Signal: " + String(WiFi.RSSI()) + " dBm</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleData() {
  String json = "{\"temperature\":" + String(readTemperature(), 1) +
                ",\"humidity\":" + String(readHumidity(), 1) +
                ",\"co2\":" + String(readCO2()) + "}";
  server.send(200, "application/json", json);
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
  Serial.print("Open: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}