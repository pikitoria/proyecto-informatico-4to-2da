#define boton 4
#define led 2

bool ultimoBoton = LOW;
int contador = 0;

int secuencia[5] = {};

void setup()
{
  Serial.begin(3800);
  pinMode(2,OUTPUT);
  
  pinMode(boton,INPUT);
}

void loop()
{
 
  bool botonActual = digitalRead(boton);

  if (botonActual == HIGH && ultimoBoton == LOW)
  {
    contador++;
    delay(50);
  }
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(led, HIGH);
    delay(1000);
    if (digitalRead(boton) == HIGH)
    {
      secuencia[i] = 1;
      digitalWrite(led, LOW);
      delay(1000);
    }
    else
    {
      secuencia[i] = 0;
      digitalWrite(led, LOW);
      delay(1000);
    }
  }
  
  for (int i = 0; i < 5; i++)
  {
    Serial.println(secuencia[i]);
  }
  Serial.println("---");
  
  ultimoBoton = botonActual;

}