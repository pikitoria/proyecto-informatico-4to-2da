int potR = A0;
int potG = A1;
int potB = A2;

int ledR = 9;
int ledG = 10;
int ledB = 11;

void setup() {
  pinMode( 9 , OUTPUT );
  pinMode( 10 , OUTPUT );
  pinMode( 11 , OUTPUT );
}

void loop() {
  int valR = analogRead(A0);
  int valG = analogRead(A1);
  int valB = analogRead(A2);

  valR = map(valR, 0, 1023, 0, 255);
  valG = map(valG, 0, 1023, 0, 255);
  valB = map(valB, 0, 1023, 0, 255);

  analogWrite( 9 , valR );
  analogWrite( 10 , valG );
  analogWrite( 11 , valB );
}