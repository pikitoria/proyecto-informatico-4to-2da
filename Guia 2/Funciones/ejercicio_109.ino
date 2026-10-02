void MultiplosDe10(int vector[], int tamano) 
{
  for (int i = 0; i < tamano; i++) 
  {
    vector[i] = random(0, 11) * 10;
  }
}

void setup() 
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  int Vector[5];
  int cantidad = 5;

  MultiplosDe10(Vector, cantidad);

  Serial.println("Multiplos de 10:");
  for (int i = 0; i < cantidad; i++) 
  {
    Serial.print("Posicion ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(Vector[i]);
  }
}

void loop() 
{
}