// Defina o pino para o sensor de luminosidade
const int luminosityPin = 34;  // Exemplo de pino analógico

// Variável para armazenar o valor da luminosidade
int luminosity = 0;

void setup() {
  // Inicia a comunicação serial
  Serial.begin(115200);

  // Inicializa o pino do sensor de luminosidade como entrada
  pinMode(luminosityPin, INPUT);
}

void loop() {
  // Leitura do valor da luminosidade
  luminosity = analogRead(luminosityPin);

  // Verifica se o valor da luminosidade está abaixo do limite
  if (luminosity < 2000) {
    Serial.println("Período do dia: Dia");
  } else {
    Serial.println("Período do dia: Noite");
  }


  // Atraso de 1 segundo antes de ler novamente
  delay(1000);
}
