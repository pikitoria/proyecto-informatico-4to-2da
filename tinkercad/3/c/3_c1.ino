const int boton = 2;
const int pot = A0;

int leds[] = {3,4,5,6,7,8,9,10,11,12}; 
bool estado = false;

void setup() {
  pinMode(boton, INPUT);
  
  for(int i=0; i<10; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int lecturaBoton = digitalRead(boton);

  if(lecturaBoton == HIGH){
    estado = true;
  }

  if(estado){
    int valorPot = analogRead(pot);
    
    int tiempo = map(valorPot, 0, 1023, 50, 1000);

    for(int i=0; i<10; i++){
      digitalWrite(leds[i], HIGH);
      delay(tiempo);
    }

    for(int i=9; i>=0; i--){
      digitalWrite(leds[i], LOW);
      delay(tiempo);
    }
  }
}