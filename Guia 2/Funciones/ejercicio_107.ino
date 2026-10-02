void ordenarMayorAMenor(int vector[], int tamano) 
{
  for (int i = 0; i < tamano - 1; i++) 
  {
    for (int j = 0; j < tamano - i - 1; j++) 
    {
      if (vector[j] < vector[j + 1]) 
      {
        int aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }
}

void setup() {
  Serial.begin(9600);

  int numeros[] = {50, 90, 60, 70, 80};
  int cantidad = 5;

  Serial.println("Vector original:");
  imprimirVector(numeros, cantidad);

  ordenarMayorAMenor(numeros, cantidad);

  Serial.println("Vector ordenado de mayor a menor:");
  imprimirVector(numeros, cantidad);
}

void loop() {
}

void imprimirVector(int vector[], int tamano) 
{
  for (int i = 0; i < tamano; i++)
  {
    Serial.print(vector[i]);
    Serial.print("  ");
  }
  Serial.println();
}