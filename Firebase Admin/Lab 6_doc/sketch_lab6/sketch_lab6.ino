#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";
const char* serverUrl = "http://<your-server-IP>:3000/data";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Example JSON data
    String jsonData = "{\"temperature\": 25, \"humidity\": 60}";

    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.println("Data sent successfully!");
    } else {
      Serial.print("Error sending data. Code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }

  delay(10000); // Send every 10 seconds
}
