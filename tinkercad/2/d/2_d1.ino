int potPin = A0;

int ledMagentaR = 3;
int ledMagentaB = 5;

int ledAmarilloR = 6;
int ledAmarilloG = 9;

void setup() {
  pinMode(ledMagentaR, OUTPUT);
  pinMode(ledMagentaB, OUTPUT);
  
  pinMode(ledAmarilloR, OUTPUT);
  pinMode(ledAmarilloG, OUTPUT);
}

void loop() {
  int valor = analogRead(potPin);

  // Mapear velocidad (más valor = más lento)
  int tiempo = map(valor, 0, 1023, 100, 1000);

  // Encender LEDs
  digitalWrite(ledMagentaR, HIGH);
  digitalWrite(ledMagentaB, HIGH);

  digitalWrite(ledAmarilloR, HIGH);
  digitalWrite(ledAmarilloG, HIGH);

  delay(tiempo);

  // Apagar LEDs
  digitalWrite(ledMagentaR, LOW);
  digitalWrite(ledMagentaB, LOW);

  digitalWrite(ledAmarilloR, LOW);
  digitalWrite(ledAmarilloG, LOW);

  delay(tiempo);
}