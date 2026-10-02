void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int resultado = lanzarDado(6);
  Serial.print("Resultado del lanzamiento: ");
  Serial.println(resultado);
  
  delay(2000); 
}

int lanzarDado(int lados) {
  return random(1, lados + 1);
}