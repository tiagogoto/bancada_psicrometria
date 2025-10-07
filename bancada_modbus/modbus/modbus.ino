#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <ModbusIP_ESP8266.h>
#define D2 4
#define D3 0
#define D4 2
#define TIPODHT DHT22 // Define o sensor que será utilizado
#define LEDonBoard 2  


const char* ssid = "Bancada Psicrométrica"; // Nome da rede WiFi
const char* password = "12345678"; // Senha da rede WiFi
float umidade1=0;
float umidade2=0;
float Temperatura1=0;
float Temperatura2=0;
float Temperatura3=0;
float Temperatura4=0;

typedef union{
  float fvalue;
  word reg[2];
} mbFloat;


DHT dht(D3, TIPODHT); // Inicializa o sensor DHT
DHT dht2(D4, TIPODHT);
OneWire oneWire(D2);
DallasTemperature sensors(&oneWire);
ModbusIP mb;

void setup() {
  Serial.begin(115200);

  IPAddress staticIP(192, 168, 4, 2); // Define como IP estatico
  IPAddress gateway(192, 168, 4, 1); // Define como IP estatico
  IPAddress subnet(255, 255, 255, 0); // Sub-rede definida como estática

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password, 2,0);
  WiFi.config(staticIP, gateway, subnet);
  //WiFi.begin(ssid, password);

 
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  mb.server(4444);
  mb.addHreg(umidade1);
  mb.addHreg(umidade2);
  mb.addHreg(Temperatura1);
  mb.addHreg(Temperatura2);
  mb.addHreg(Temperatura3);
  mb.addHreg(Temperatura4);
 /* for (int i = 0; i < 20; i++) {
    mb.addHreg(i, 0); // Initialize all holding registers to zero
  }
  */
  dht.begin();  // Começa a ler o sensor DHT22
  dht2.begin(); // Começa a ler o sensor DHT22
  sensors.begin(); // Começa a ler os sensores DS18B20
  
  
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  mb.task();
  mbFloat umidade1float = dht.readHumidity();
  mb.Hreg(umidade1, );
  Serial.println(dht.readHumidity());
  delay(500);
}
