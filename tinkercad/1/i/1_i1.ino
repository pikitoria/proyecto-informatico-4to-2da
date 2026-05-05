const int boton = 2;
bool estadoSecuencia = true;

int leds[] = {3,4,5,6,7,8,9,10,11,12};
int cantidad = 10;

int indice = 0;

unsigned long ultimoTiempoBoton = 0;
int estadoAnterior = HIGH;

void setup() {
  pinMode(boton, INPUT_PULLUP);

  for(int i = 0; i < cantidad; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int lectura = digitalRead(boton);

  if(lectura == LOW && estadoAnterior == HIGH && millis() - ultimoTiempoBoton > 200){
    estadoSecuencia = !estadoSecuencia;
    ultimoTiempoBoton = millis();
  }

  estadoAnterior = lectura;

  if(estadoSecuencia){
    for(int i = 0; i < cantidad; i++){
      digitalWrite(leds[i], LOW);
    }

    digitalWrite(leds[indice], HIGH);

    indice++;
    if(indice >= cantidad){
      indice = 0;
    }

    delay(200);
  }
}