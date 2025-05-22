/*
██╗     ██╗   ██╗ ██████╗ ██████╗  █████╗ ███████╗
██║     ██║   ██║██╔═════╗██╔══██╗██╔══██╗██╔════╝
██║     ██║   ██║██║     ║██████╔╝███████║███████╗
██║     ██║   ██║██║     ║██╔══██╗██╔══██║╚════██║
███████╗╚██████╔╝╚██████╔╝██║  ██║██║  ██║███████║
╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝
-----------------------------------------------------------
📌 Autor: Lucas Galindo
🔗 GitHub: https://github.com/Lucras22
📧 E-mail: devlucasgalindo@email.com
💼 LinkedIn: https://www.linkedin.com/in/lucasgalindoiot/
-----------------------------------------------------------
📜 Instruções de Uso:
- 
-----------------------------------------------------------
📂 Repositório do Projeto:
🔗 https://github.com/Lucras22/IrrigaClima
-----------------------------------------------------------
🫱🏻‍🫲🏻 Parceiros:
🔗 https://github.com/jaogabriel01
-----------------------------------------------------------
🛠️ Licença: ....
*/

#define PINO_SENSOR_TDS 35
#define VOLTAGEM_REFERENCIA 3.3
#define AMOSTRAS 30
#define INTERVALO_AMOSTRAS 20
#define FATOR_CALIBRACAO 0.79
#define FATOR_TDS_PADRAO 0.5

// Protótipos de funções
float lerCondutividadeMicroSiemens();  // Renomeada para ficar claro que retorna µS/cm
float converterCEparaTDS(float ce, float fator = 0.5);
float microSiemensParaMilliSiemens(float microS);  // Nova função de conversão

void setup() {
  Serial.begin(9600);
  pinMode(PINO_SENSOR_TDS, INPUT);
  Serial.println("Sistema TDS/CE - Unidade em mS/cm");
}

void loop() {
  // Obtém condutividade em µS/cm
  float ceMicroSiemens = lerCondutividadeMicroSiemens();
  
  // Converte para mS/cm
  float ceMilliSiemens = microSiemensParaMilliSiemens(ceMicroSiemens);
  
  // Converte para TDS (ppm)
  float tds = converterCEparaTDS(ceMicroSiemens, FATOR_TDS_PADRAO);
  
  // Exibe resultados
  Serial.print("CE: ");
  Serial.print(ceMilliSiemens, 3);  // 3 casas decimais para mS/cm
  Serial.print(" mS/cm | TDS: ");
  Serial.print(tds, 1);
  Serial.println(" ppm");
  
  delay(2000);
}

float lerCondutividadeMicroSiemens() {
  // 1. Leitura analógica com média móvel
  float somaLeituras = 0;
  for (int i = 0; i < AMOSTRAS; i++) {
    somaLeituras += analogRead(PINO_SENSOR_TDS);
    delay(INTERVALO_AMOSTRAS);
  }
  float leituraMedia = somaLeituras / AMOSTRAS;

  // 2. Cálculo da condutividade em µS/cm
  float tensao = (leituraMedia * VOLTAGEM_REFERENCIA) / 4096.0;
  float condutividade = (tensao / FATOR_CALIBRACAO) * 1000;
  
  return condutividade;
}

float microSiemensParaMilliSiemens(float microS) {
  // Converte µS/cm para mS/cm (divide por 1000)
  return microS / 1000.0;
}

float converterCEparaTDS(float ce, float fator) {
  return ce * fator;
}

// Função auxiliar para calibração
void calibrarParaMilliSiemens(float valorReferencia) {
  Serial.println("\n=== Modo Calibração ===");
  Serial.print("Use uma solução de ");
  Serial.print(valorReferencia);
  Serial.println(" mS/cm");
  
  float ceMedida = lerCondutividadeMicroSiemens() / 1000;  // Já em mS/cm
  float diferencaPercentual = ((ceMedida - valorReferencia)/valorReferencia) * 100;
  
  Serial.print("Valor medido: ");
  Serial.print(ceMedida, 3);
  Serial.println(" mS/cm");
  
  Serial.print("Diferença: ");
  Serial.print(diferencaPercentual, 1);
  Serial.println("%");
  
  if (abs(diferencaPercentual) > 5.0) {
    Serial.println("Ajuste FATOR_CALIBRACAO no código:");
    Serial.print("Valor atual: ");
    Serial.println(FATOR_CALIBRACAO);
    Serial.print("Novo valor sugerido: ");
    Serial.print(FATOR_CALIBRACAO * (valorReferencia/ceMedida), 4);
  }
  Serial.println("======================");
}
