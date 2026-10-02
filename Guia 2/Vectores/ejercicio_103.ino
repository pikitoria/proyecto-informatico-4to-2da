float valores[] = {5.4, 5.39, 5.38, 5.31, 5.21, 5.03, 4.45, 3.95, 2.6, 1.49};
int cantidad = 10;
float mayor;

void setup() {
  Serial.begin(9600);
  mayor = valores[0];

  for (int i = 1; i < cantidad; i++) {
    if (valores[i] > mayor) {
      mayor = valores[i];
    }
  }

  Serial.print("El número más grande del vector es: ");
  Serial.println(mayor);
}

void loop() {
}
