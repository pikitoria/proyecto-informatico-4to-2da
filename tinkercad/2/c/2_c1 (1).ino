// C++ code
//
void setup()
{
  pinMode( 5 , OUTPUT );
  pinMode( 3 , OUTPUT );
  pinMode( 6 , OUTPUT );
}

void loop()
{
  analogWrite( 5 , 0 );
  analogWrite( 6 , 0 );
  delay(1000);
  analogWrite( 5 , 100 );
  analogWrite( 3 , 100 );
  analogWrite( 6 , 0 );
  delay(1000);
  analogWrite( 5 , 0 );
  analogWrite( 3 , 0 );
  analogWrite( 6 , 100 );
  delay(1000);
  analogWrite( 5 , 100 );
  analogWrite( 3 , 0 );
  analogWrite( 6 , 100 );
  delay(1000);
}