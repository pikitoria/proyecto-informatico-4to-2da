int buttonState = 0;
int lastbuttonState = HIGH;
int estado = 0;
void setup()
{
  pinMode(8, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(8);
  if (buttonState == LOW && lastbuttonState == HIGH)
   {
        estado++;
        if (estado > 2)
      {
          estado = 0;
      }
   }
  lastbuttonState = buttonState;
      digitalWrite( 4 , LOW );
      digitalWrite( 3 , LOW );
      digitalWrite( 5 , LOW );
      
  if (estado == 0)
  {
    digitalWrite( 3 , HIGH );  
  } 
  else if (estado == 1)
  {
    digitalWrite( 3 , LOW );

    
    digitalWrite( 4 , HIGH );

   }
 else if (estado == 2)
  {
    digitalWrite( 4 , LOW );
   
    digitalWrite( 5 , HIGH );

  }
}