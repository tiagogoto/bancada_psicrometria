#include <ESP8266WiFi.h>

#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define TIPODHT DHT22
#define LEDonBoard 2
#define PINO3 3
#define PINO4 4

const char* ssid = "UFR";
const char* password = "";

DHT dht(PINO3, TIPODHT);
DHT dht2(PINO4, TIPODHT);
OneWire onewire(2);
DallasTemperature sensores(&onewire); 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  dht2.begin();
  sensores.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
