
#include <ESP8266WiFi.h> // Biblioteca do NodeMCU ESP8266
#include <ESP8266WebServer.h> // Biblioteca do NodeMCU ESP8266
#include "DHT.h"  // Biblioteca dos sensores DHT22
#include <OneWire.h> // Biblioteca do DS18B20
#include <DallasTemperature.h> // Biblioteca do DS18B20
#include "PageIndex.h" // Inclui o conteúdo da página da Web da interface do usuário

#define BARRAMENTO 4 // O fio de dados está conectado A GPIO 4
#define TIPODHT DHT22 // Define o sensor que será utilizado
#define LEDonBoard 2  // Define o LED da placa
#define D3 3
#define D4 4

const char* ssid = "Bancada Psicrométrica"; // Nome da rede WiFi
const char* password = "12345678"; // Senha da rede WiFi

ESP8266WebServer server(80);

DHT dht(D3, TIPODHT); // Inicializa o sensor DHT
DHT dht2(D4, TIPODHT); // Inicializa o sensor DHT

// Comunica com seus dispositivos OneWire
OneWire oneWire(BARRAMENTO);

// Passa referência oneWire para a biblioteca Dallas Temperature
DallasTemperature sensors(&oneWire);

// Abre o endereço IP do NodeMCU ESP8266 no navegador
void handleRoot() {
 String s = MAIN_page; // Le o conteúdo html
 server.send(200, "text/html", s); //Envia a pagina da Web
}

// Le o valor de temperatura de um sensor DHT22
void handleDHT221Temperature() {
  float t = dht.readTemperature();  // Le a temperatura em Celsius
  String ValorTemperatura1 = String(t);

//Envia o valor da temperatura apenas quando é solicitado
   server.send(200, "text/plane", ValorTemperatura1); 
}

// Leitura do valor de temperatura de um sensor DHT22
void handleDHT222Temperature() {
  float t = dht2.readTemperature();  // Le a temperatura em Celsius
  String ValorTemperatura2 = String(t);
 
 // Envia o valor da temperatura apenas quando é solicitado
  server.send(200, "text/plane", ValorTemperatura2); 
}

// Leitura  do valor da umidade de um sensor DHT22
void handleDHT221Humidity() {
  float h = dht.readHumidity();
  String ValorUmidade1 = String(h);
 
 // Envia o valor da temperatura apenas quando é solicitado
  server.send(200, "text/plane", ValorUmidade1); 

}

// Leitura do valor da umidade de um sensor DHT22
void handleDHT222Humidity() {
  float h = dht2.readHumidity();
  String ValorUmidade2 = String(h);
 
 // Envia o valor da temperatura apenas quando é solicitado
  server.send(200, "text/plane", ValorUmidade2); 

}

String readDSTemperatureC1() {
  // Temperaturas e verificação a todos os dispositivos no barramento
  sensors.requestTemperatures(); 
  float tempC1 = sensors.getTempCByIndex(0);
  String ValorTemperatura3 = String(tempC1);
 
  server.send(200, "text/plane", ValorTemperatura3);
  return String(tempC1);
}

String readDSTemperatureC2() {
  // Temperaturas e verificação a todos os dispositivos no barramento
  sensors.requestTemperatures(); 
  float tempC2 = sensors.getTempCByIndex(1);
  String ValorTemperatura4 = String(tempC2);
 
  server.send(200, "text/plane", ValorTemperatura4);
 return String(tempC2);
}

String readDSTemperatureC3() {
  // Temperaturas e verificação a todos os dispositivos no barramento
  sensors.requestTemperatures(); 
  float tempC3 = sensors.getTempCByIndex(2);
  String ValorTemperatura5 = String(tempC3);
 
  server.send(200, "text/plane", ValorTemperatura5);
 return String(tempC3);
}

String readDSTemperatureC4() {
  // Temperaturas e verificação a todos os dispositivos no barramento
  sensors.requestTemperatures(); 
  float tempC4 = sensors.getTempCByIndex(3);
  String ValorTemperatura6 = String(tempC4);
 
  server.send(200, "text/plane", ValorTemperatura6);
 return String(tempC4);
}

void setup(){
  
  Serial.begin(115200); // Inicia porta serial

  IPAddress staticIP(192, 168, 4, 2); // Define como IP estatico
  IPAddress gateway(192, 168, 4, 1); // Define como IP estatico
  IPAddress subnet(255, 255, 255, 0); // Sub-rede definida como estática

  WiFi.mode(WIFI_AP); // Modo de trabalho como ponto de acesso

  WiFi.softAP(ssid, password, 2, 0);
  WiFi.config(staticIP, gateway, subnet);

  dht.begin();  // Começa a ler o sensor DHT22
  dht2.begin(); // Começa a ler o sensor DHT22
  sensors.begin(); // Começa a ler os sensores DS18B20
  delay(500);

  server.on("/", handleRoot); // Exibi a página da web
  server.on("/readTemperature1", handleDHT221Temperature);  // Solicita o handleDHT22Temperature.
  server.on("/readHumidity1", handleDHT221Humidity);  // Solicita o handleDHT11Humidity.
  server.on("/readTemperature2", handleDHT222Temperature);  // Solicita o handleDHT22Temperature.
  server.on("/readHumidity2", handleDHT222Humidity); // Solicita o handleDHT11Humidity.
  server.on("/temperaturec1", readDSTemperatureC1); // Solicita o readDSTemperatureC1
  server.on("/temperaturec2", readDSTemperatureC2); // Solicita o readDSTemperatureC2
  server.on("/temperaturec3", readDSTemperatureC3); // Solicita o readDSTemperatureC3
  server.on("/temperaturec4", readDSTemperatureC4); // Solicita o readDSTemperatureC4
  

  server.begin(); // Inicia o WebServer
  Serial.println("Servidor HTTP iniciado.");
  Serial.println(WiFi.softAPIP());
  

}
void leitura_serial()
{
  Serial.print("Sensor 1 - umidade: ");
  Serial.println(dht.readHumidity());
  Serial.print("Sensor 2 - umidade: ");
  Serial.println(dht2.readHumidity());
  delay(1000);
}
void loop(){ 
  server.handleClient();  // Solicitações do usuário 
  }
