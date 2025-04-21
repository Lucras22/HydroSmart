// Define o pino ao qual o sensor TDS está conectado
const int tdsPin = 15;  // Alterar conforme o pino de conexão

void setup() {
  Serial.begin(115200);
  pinMode(tdsPin, INPUT);
}

void loop() {
  // Leitura do valor do sensor TDS
  int tdsValue = analogRead(tdsPin);

  // Converte o valor do sensor em milivolts (mV)
  float condutivy = tdsValue * 2;
  Serial.print("TDS Value (PPM): ");
  Serial.println(tdsValue);
  Serial.print("Condutividade Eletrica (ECC): ");
  Serial.println(condutivy);

  // Aqui você pode adicionar uma fórmula para converter a tensão em TDS em ppm se necessário
  // Exemplo: TDS (ppm) = (Voltagem em mV - Valor de calibração) / Fator de conversão

  delay(1000); // Espera 1 segundo antes da próxima leitura
}
