int potPin = A0;
int buzzer = 8;
int valor;
int frecuencia;

void setup() {
  pinMode( 8 , OUTPUT );
}

void loop() {
  valor = analogRead(A0);

  frecuencia = map(valor, 0, 1023, 100, 2000);

  tone( 8 , frecuencia );

  delay(50);
}