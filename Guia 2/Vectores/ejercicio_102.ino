int datos[] = {10, 4, 2};
int cantidad = 3;

void setup() {
  Serial.begin(9600);
  int aux;

  for (int i = 0; i < cantidad - 1; i++) {
    for (int j = i + 1; j < cantidad; j++) {
      if (datos[i] > datos[j]) {
        aux = datos[i];
        datos[i] = datos[j];
        datos[j] = aux;
      }
    }
  }

  Serial.println("Vector ordenado de menor a mayor:");
  for (int i = 0; i < cantidad; i++) {
    Serial.println(datos[i]);
  }
}

void loop() {
}
