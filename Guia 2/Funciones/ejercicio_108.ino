bool esMultiplo(int numero, int divisor) {
if (divisor == 0) {
return false;
}

return numero % divisor == 0;
}

void setup() {
Serial.begin(9600);

int numeros[5] = {10, 15, 22, 30, 41};

for (int i = 0; i < 5; i++) {
if (esMultiplo(numeros[i], 5)) {
Serial.print(numeros[i]);
Serial.println(" es multiplo de 5");
} else {
Serial.print(numeros[i]);
Serial.println(" no es multiplo de 5");
}
}
}

void loop() {
}
