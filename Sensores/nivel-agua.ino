const int PINO_TRIG = 4; // Pino D4 conectado ao TRIG do HC-SR04
const int PINO_ECHO = 2; // Pino D2 conectado ao ECHO do HC-SR04

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(PINO_TRIG, OUTPUT); // Configura o pino TRIG como saída
  pinMode(PINO_ECHO, INPUT); // Configura o pino ECHO como entrada
}

void loop() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);
  
  long duracao = pulseIn(PINO_ECHO, HIGH); // Mede o tempo de resposta do ECHO  
  float distancia = (duracao * 0.0343) / 2; // Calcula a distância usando a velocidade do som (aproximadamente 343 m/s)
  
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Verifica o nível de água e imprime a condição
  if (distancia > 23) {
    Serial.println("Nível baixo (mais que 23 cm de água)");
  } else if (distancia >= 11.5 && distancia <= 23) {
    Serial.println("Nível médio (11,5 a 23 cm de água)");
  } else if (distancia < 11.5) {
    Serial.println("Nível alto (menos que 11,5 cm de água)");
  }

  delay(1000); // Aguarda 1 segundo antes de fazer a próxima leitura
}
