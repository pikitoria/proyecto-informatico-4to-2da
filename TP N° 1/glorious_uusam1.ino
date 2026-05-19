int led1R = 3;
int led1G = 4;
int led1B = 2;

int led2R = 5;
int led2G = 7;
int led2B = 6;

int led3R = 8;
int led3G = 10; 
int led3B = 9;   

int buzzer = 11;

void setup() {
  pinMode( 3 , OUTPUT );
  pinMode( 4 , OUTPUT );
  pinMode( 2 , OUTPUT );

  pinMode( 5 , OUTPUT );
  pinMode( 7 , OUTPUT );
  pinMode( 6 , OUTPUT );

  pinMode( 8 , OUTPUT );
  pinMode( 10 , OUTPUT );
  pinMode( 9 , OUTPUT );

  pinMode( 11 , OUTPUT );
}

void apagarTodo() {
  analogWrite( 3 , 0 );
  digitalWrite( 4 , LOW );
  digitalWrite( 2 , LOW );

  digitalWrite( 5 , LOW );
  digitalWrite( 7 , LOW );
  digitalWrite( 6 , LOW );

  digitalWrite( 8 , LOW );
  analogWrite( 10 , 0 );
  analogWrite( 9 , 0 );
}

void beep() {
  analogWrite( 11 , 150 );
  delay(80);             
  analogWrite( 11 , 0 );
}

void loop() {

  apagarTodo();
  analogWrite( 3 , 255 );
  beep();
  delay(1000);

  apagarTodo();
  digitalWrite( 5 , HIGH );
  digitalWrite( 6 , HIGH );
  beep();
  delay(1000);

  apagarTodo();
  analogWrite( 10 , 80 );
  analogWrite( 9 , 80 );
  beep();
  delay(1000);
}