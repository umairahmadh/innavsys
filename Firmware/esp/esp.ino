#include <espSoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

// Constants
const char* ssid = "project";
const char* password = "project123";

#define RXD2 16
#define TXD2 17
#define D5 14
#define D6 12
SoftwareSerial swSer;

int wifi_led = 2;
int wificlient_led = 15;


// Globals
WebSocketsServer webSocket = WebSocketsServer(80);


// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num,
                      WStype_t type,
                      uint8_t * payload,
                      size_t length) {

  // Figure out the type of WebSocket event
  switch (type) {

    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      digitalWrite(wificlient_led, LOW);
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        Serial.println(ip.toString());
        digitalWrite(wificlient_led, HIGH);
      }
      break;

    // Echo text message back to client
    case WStype_TEXT:
      {
        Serial.printf("[%u] Text: %s\n", num, payload);
        //Serial.println(num);
        String payloadstr = (char*) payload;
        //Serial2.write(payloadstr);
        // Serial.write(str(payload).encode())
        // long payloadint = payload;
        swSer.print(payloadstr);
        Serial.println(payloadstr);

        while (!swSer.available() ) {
          // Serial.println("In side the loop");
        }
        String buff = swSer.readString();
        Serial.print("I received : ");
        Serial.println(buff);
        delay(500);
        //   webSocket.sendTXT(num, payloadstr);
        webSocket.sendTXT(num, buff);
        //   data2arrays(payloadstr);

        /*

          //Arduino JSON stuff
          DynamicJsonDocument doc(1024);
          DeserializationError error = deserializeJson(doc, payloadstr);
          if (error) {
          Serial.print(F("deserializeJson() failed: "));
          Serial.println(error.c_str());
          return;
          }

          int num = doc["num"];
          int angle_1 = doc["angle"][4];
          int dis_1 = doc["distance"][5];
          Serial.println(angle_1);
          Serial.println(dis_1);
        */


        //webSocket.sendTXT(num, payload);
      }
      break;

    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}

void setup() {

  // Start Serial port
  Serial.begin(9600);
  pinMode(wifi_led, OUTPUT);
  pinMode(wificlient_led, OUTPUT);
  digitalWrite(wifi_led, LOW);
  digitalWrite(wificlient_led, LOW);
  // Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  swSer.begin(9600, SWSERIAL_8N1, D5, D6, false, 95, 11);
  // Connect to access point
  Serial.println("Connecting");
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }

  // Print our IP address
  Serial.println("Connected!");
  digitalWrite(wifi_led, HIGH);
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());
    swSer.println("Connected!");
  swSer.print("My IP address: ");
  swSer.println(WiFi.localIP());

  // Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
}

void loop() {

  // Look for and handle WebSocket data
  webSocket.loop();
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifi_led, LOW);
  }
  else if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(wifi_led, HIGH);
  }
}
