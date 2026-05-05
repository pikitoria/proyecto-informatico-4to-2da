int buttonState = 0;
int lastbuttonState = HIGH;
int estado = 0;
void setup()
{
  pinMode(4, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  buttonState = digitalRead(4);
  if (buttonState == LOW && lastbuttonState == HIGH)
   {
        estado++;
        if (estado > 6)
      {
          estado = 0;
      }
   }
  lastbuttonState = buttonState;
  
  digitalWrite( 2 , LOW );
  digitalWrite( 3 , LOW );
  digitalWrite( 5 , LOW );
  
  if (estado == 0)
  {
    digitalWrite ( 5 , HIGH);
    digitalWrite( 2 , LOW );
    digitalWrite( 3 , LOW );
  }
  else if (estado == 1)
  {
    digitalWrite( 5 , LOW );
    digitalWrite( 2 , HIGH );
    digitalWrite( 3 , HIGH );
  }
  else if (estado == 2)
  {
    digitalWrite( 5 , LOW );
    digitalWrite( 2 , HIGH );
    digitalWrite( 3 , LOW );
  }
  else if (estado == 3)
  {
    digitalWrite( 5 , HIGH );
    digitalWrite( 2 , LOW );
    digitalWrite( 3 , HIGH );
  }
  else if (estado == 4)
  {
    digitalWrite( 5 , LOW );
    digitalWrite( 2 , LOW );
    digitalWrite( 3 , HIGH );
  }
  else if (estado == 5)
  {
    digitalWrite( 5 , LOW );
    digitalWrite( 2 , LOW );
    digitalWrite( 3 , LOW );
    
    digitalWrite( 5 , HIGH );
    digitalWrite( 2 , HIGH );
    digitalWrite( 3 , HIGH );
  }
  else if (estado = 6)
  {
    digitalWrite( 5 , HIGH );
    digitalWrite( 2 , HIGH );
    digitalWrite( 3 , LOW );
  }
}