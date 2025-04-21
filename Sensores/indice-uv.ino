#define UV_PIN 33

void setup() 
{
   pinMode(UV_PIN, INPUT);
  
  Serial.begin(115200);
}
 
void loop() 
{

   // índice UV
    int leitura_porta = analogRead(UV_PIN);
    int uv;

    // De acordo com a leitura define o indice UV correspondente
    if (leitura_porta <= 10) {
        uv = 0;
    } else if (leitura_porta > 10 && leitura_porta <= 46) {
        uv = 1;
    } else if (leitura_porta > 46 && leitura_porta <= 65) {
        uv = 2;
    } else if (leitura_porta > 65 && leitura_porta <= 83) {
        uv = 3;
    } else if (leitura_porta > 83 && leitura_porta <= 103) {
        uv = 4;
    } else if (leitura_porta > 103 && leitura_porta <= 124) {
        uv = 5;
    } else if (leitura_porta > 124 && leitura_porta <= 142) {
        uv = 6;
    } else if (leitura_porta > 142 && leitura_porta <= 162) {
        uv = 7;
    } else if (leitura_porta > 162 && leitura_porta <= 180) {
        uv = 8;
    } else if (leitura_porta > 180 && leitura_porta <= 200) {
        uv = 9;
    } else if (leitura_porta > 200 && leitura_porta <= 221) {
        uv = 10;
    } else {
        uv = 11;
    }

  Serial.print("indice do Sensor UV = ");
  Serial.print(uv);
  Serial.print("\n");

  delay(10000);
  
}
