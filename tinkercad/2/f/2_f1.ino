int potPin = A0;
int ledPin = 9;

int valorPot = 0;
int tiempo = 0;

void setup() {
  pinMode( 9 , OUTPUT );
}

void loop() {
  valorPot = analogRead(A0);

  tiempo = map(valorPot, 0, 1023, 0, 10000);

  digitalWrite( 9 , HIGH );
  delay(tiempo);

  digitalWrite( 9 , LOW );
  delay(tiempo);
}