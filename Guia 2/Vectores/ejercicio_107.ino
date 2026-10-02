
int leds[] = {2, 3, 4, 5, 6};  
int cantidad = 5;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < cantidad; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.println("Iniciando escalera de luces...");
}

void loop() {
  for (int i = 0; i < cantidad; i++) {
    digitalWrite(leds[i], HIGH);
    Serial.print("LED ");
    Serial.print(i + 1);
    Serial.println(" encendido");
    delay(400);
  }

  for (int i = cantidad - 1; i >= 0; i--) {
    digitalWrite(leds[i], LOW);
    Serial.print("LED ");
    Serial.print(i + 1);
    Serial.println(" apagado");
    delay(400);
  }
}
