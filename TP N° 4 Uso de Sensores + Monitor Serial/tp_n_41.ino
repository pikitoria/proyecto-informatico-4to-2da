int tempPin = A0;
int ldrPin = A1;

int rojo = 9;
int verde = 10;
int azul = 11;

void setup() {
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  int valorTemp = analogRead(A0);

  float voltaje = valorTemp * (5.0 / 1023.0);

  float temperatura = voltaje * 100.0;

  int valorLDR = analogRead(A1);

  int luz = map(valorLDR, 0, 1023, 100, 0);

  Serial.print("El nivel de luz actual es: ");
  Serial.print(luz);
  Serial.print("% y la temperatura actual: ");
  Serial.print(temperatura);
  Serial.println(" °c");

  digitalWrite(rojo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);

  if (luz >= 30 && luz <= 70) {

    if (temperatura > 90) {
      digitalWrite(9, HIGH);
    }

    else if (temperatura < 18) {
      digitalWrite(10, HIGH);
    }

    else {
      digitalWrite(11, HIGH);
    }
  }

  delay(1000);
}