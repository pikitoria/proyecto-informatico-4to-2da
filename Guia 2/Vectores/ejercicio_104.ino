int led = 7;  
int secuencia[] = {1, 0, 0, 1, 1, 0, 1, 1};  
int cantidad = 8;  

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Iniciando secuencia de luces...");
}

void loop() {
  for (int i = 0; i < cantidad; i++) {
    if (secuencia[i] == 1) {
      digitalWrite(led, HIGH);  
      Serial.print("Paso ");
      Serial.print(i + 1);
      Serial.println(": LED encendido");
    } else {
      digitalWrite(led, LOW);   
      Serial.print("Paso ");
      Serial.print(i + 1);
      Serial.println(": LED apagado");
    }
    delay(500);  
  }
}
