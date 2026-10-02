int pines[] = {2, 3, 4, 5};
int cantidad = sizeof(pines) / sizeof(pines[0]);

void activarPines(int vectorPines[], int cantidadPines) {
for (int i = 0; i < cantidadPines; i++) {
digitalWrite(vectorPines[i], HIGH);
}
}

void setup() {
for (int i = 0; i < cantidad; i++) {
pinMode(pines[i], OUTPUT);
}

activarPines(pines, cantidad);
}

void loop() {
}