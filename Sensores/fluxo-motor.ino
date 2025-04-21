// Pino onde o fio amarelo (sinal) do sensor está conectado
const int waterFluxPin = 13;

// Variável para armazenar o estado atual do sensor
int waterFlux = LOW;

void setup() {
  // Inicializa o monitor serial para visualização dos dados
  Serial.begin(115200);

  // Configura o pino do sensor de fluxo como entrada
  pinMode(waterFluxPin, INPUT);
}

void loop() {
  // Lê o estado do pino do sensor de fluxo
  waterFlux = digitalRead(waterFluxPin);

  if (waterFlux == HIGH) {
    Serial.println("Não Há fluxo de água");
  } else {
    Serial.println("há fluxo de água");
  }

  // Pequeno atraso para não sobrecarregar o monitor serial
  delay(500);
}
