int numeros[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int cantidad = 10;
float suma = 0;
float media = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < cantidad; i++) {
    suma += numeros[i];
  }
  media = suma / cantidad;
  Serial.print("La media del conjunto es: ");
  Serial.println(media);
}

void loop() {
}
