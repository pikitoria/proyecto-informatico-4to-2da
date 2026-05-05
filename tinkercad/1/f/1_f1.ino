#define parlante 2
#define boton 8
void setup()
{
  pinMode(parlante, OUTPUT);
  pinMode (boton,INPUT);
}

void loop()
  {
  if (digitalRead(boton) == HIGH){
    tone(parlante,440);
    delay(200);
    noTone(parlante);
    delay(200);
  }
  else{
    digitalWrite(parlante, LOW);
  }
 }

