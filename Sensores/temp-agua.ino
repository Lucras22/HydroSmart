#include <OneWire.h>
#include <DallasTemperature.h>

// Defina o pino onde o DAT está conectado
#define ONE_WIRE_BUS 4

// Crie uma instância da classe OneWire
OneWire oneWire(ONE_WIRE_BUS);

// Passe a instância OneWire para a classe DallasTemperature
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); // Solicita a leitura de temperatura
  float temperature = sensors.getTempCByIndex(0); // Obtém a temperatura do primeiro sensor
  
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  delay(2000); // Espera 2 segundos antes de ler novamente
}
