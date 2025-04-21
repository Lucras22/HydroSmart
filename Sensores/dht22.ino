#include "DHT.h"

// Defina o pino onde o sensor DHT está conectado
#define DHTPIN 4  // Pino de dados conectado ao GPIO 4 (D4)

// Defina o tipo de sensor DHT
#define DHTTYPE DHT22

// Inicialize o sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicie a comunicação serial
  Serial.begin(115200);
  
  // Inicie o sensor DHT
  dht.begin();
}

void loop() {
  // Aguarde 2 segundos entre as leituras
  delay(2000);

  // Leia a umidade relativa do ar
  float humidity = dht.readHumidity();
  
  // Leia a temperatura em Celsius
  float temperature = dht.readTemperature();
  
  // Verifique se houve falha na leitura e se sim, saia do loop
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  // Exiba os resultados no monitor serial
  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
