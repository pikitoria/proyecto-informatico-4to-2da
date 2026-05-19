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

int potTiempo = A0;
int potR = A1;
int potG = A2;
int potB = A3;

int boton = 12;


bool activo = true;
bool ultimoBoton = HIGH;

unsigned long tiempoAnterior = 0;
unsigned long intervalo = 1000;

int paso = 0;

int R, G, B;


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

  pinMode( 12 , INPUT_PULLUP );

  Serial.begin(9600);
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
  analogWrite( 11, 0 );
}

void leerPotenciometros() {
  int lectura = analogRead(A0);
  intervalo = (lectura * 3000.0) / 1023.0;

  R = (analogRead(A1) * 255.0) / 1023.0;
  G = (analogRead(A2) * 255.0) / 1023.0;
  B = (analogRead(A3) * 255.0) / 1023.0;
}

void mostrarDatos() {
  Serial.print("Tiempo: ");
  Serial.println(intervalo / 1000.0);

  Serial.print("R:"); Serial.println(R);
  Serial.print("G:"); Serial.println(G);
  Serial.print("B:"); Serial.println(B);
  Serial.println("------");
}

void controlarBoton() {
  bool lectura = digitalRead(12);

  if (lectura == LOW && ultimoBoton == HIGH) {
    activo = !activo;
    delay(150);
  }

  ultimoBoton = lectura;
}

void parpadeo() {
  for (int i = 0; i < 2; i++) {
    analogWrite( 3 , R );
    analogWrite( 4 , G );
    analogWrite( 2 , B );

    analogWrite( 5 , R );
    analogWrite( 7 , G );
    analogWrite( 6 , B );

    analogWrite( 8 , R);
    analogWrite( 10 , G);
    analogWrite( 9 , B);

    delay(100);
    apagarTodo();
    delay(100);
  }
}


void loop() {

  controlarBoton();
  leerPotenciometros();

  if (!activo) {
    apagarTodo();
    return;
  }

  unsigned long ahora = millis();

  if (ahora - tiempoAnterior >= intervalo) {

    tiempoAnterior = ahora;

    apagarTodo();
    beep();
    mostrarDatos();

    if (paso == 0) {
      analogWrite( 3 , R );
      analogWrite( 4 , G );
      analogWrite( 2 , B );
    }

    if (paso == 1) {
      analogWrite( 5 , R );
      analogWrite( 7, G );
      analogWrite( 6 , B );
    }

    if (paso == 2) {
      analogWrite( 8 , R );
      analogWrite( 9 , G );
      analogWrite( 10 , B );
    }

    parpadeo();

    paso++;
    if (paso > 2) paso = 0;
  }
}