int entradas[] = {7, 8};
int salidas[] = {2, 3, 4, 5};

void configurarPines(int pines[], int cantidad, int modo) {
for (int i = 0; i < cantidad; i++) {
pinMode(pines[i], modo);
}
}

void activarPines(int pines[], int cantidad) {
for (int i = 0; i < cantidad; i++) {
digitalWrite(pines[i], HIGH);
}
}

void setup() {
int cantidadEntradas = sizeof(entradas) / sizeof(entradas[0]);
int cantidadSalidas = sizeof(salidas) / sizeof(salidas[0]);

configurarPines(entradas, cantidadEntradas, INPUT);
configurarPines(salidas, cantidadSalidas, OUTPUT);

activarPines(salidas, cantidadSalidas);
}

void loop() {
}