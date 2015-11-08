# Implementation of Arduino Websocket over WiFi

The idea of the project is to establish connection to a websocket over
WiFi using ESP8266 WIFI MODULE - https://www.adafruit.com/products/2282, or Arduino WiFi Shield - https://www.arduino.cc/en/Main/ArduinoWiFiShield

## Notes

This library doesn't support of a Sec-Websocket-Key, it also doesn't support SSL and the use of Websockets over https.

## Installation instructions

Clone the repo and add it to the Arduino Sketchbook

## Examples

```
WebSocketClient client;

void setup() {
  Serial.begin(9600);
  client.connect(server);
  client.setDataArrivedDelegate(dataArrived);
  client.send("Hello World!");
}

void loop() {
  client.monitor();
}

void dataArrived(WebSocketClient client, String data) {
  Serial.println("Data Arrived: " + data);
}
```
