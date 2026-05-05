int rojo = 9;
int verde = 10;
int azul = 11;

int boton = 2;
int estadoBoton = 0;
bool encendido = false;

int pot = A0;
int valorPot = 0;

void setup() {
  pinMode( 9 , OUTPUT );
  pinMode( 10 , OUTPUT );
  pinMode( 11 , OUTPUT );

  pinMode( 2 , INPUT );
}

void loop() {
  estadoBoton = digitalRead(2);

  if (estadoBoton == HIGH) {
    encendido = !encendido;
    delay(300);
  }

  if (encendido) {
    valorPot = analogRead(A0);

    int rango = map(valorPot, 0, 1023, 0, 2);

    if (rango == 0) {
      analogWrite( 9 , 255 );
      analogWrite( 10 , 0 );
      analogWrite( 11 , 0 );
    }
    else if (rango == 1) {
      analogWrite( 9 , 0 );
      analogWrite( 10 , 255 );
      analogWrite( 11 , 0 );
    }
    else if (rango == 2) {
      analogWrite( 9 , 0 );
      analogWrite( 10 , 0 );
      analogWrite( 11 , 255 );
    }
  } 
  else {
    analogWrite( 9 , 0 );
    analogWrite( 10 , 0 );
    analogWrite( 11 , 0 );
  }
}