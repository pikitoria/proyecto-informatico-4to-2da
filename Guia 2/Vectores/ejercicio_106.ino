
int numeros[] = {2, 6, 10, 11};
int cantidad = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("Primeros 5 múltiplos de cada número:");
  
  for (int i = 0; i < cantidad; i++) {
    Serial.print("Número ");
    Serial.print(numeros[i]);
    Serial.print(": ");
    
    for (int j = 1; j <= 5; j++) {
      Serial.print(numeros[i] * j);
      Serial.print(" ");
    }
    Serial.println(); 
  }
}

void loop() {
}
