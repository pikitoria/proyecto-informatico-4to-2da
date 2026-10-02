#include <LiquidCrystal.h>

// LiquidCrystal (RS, E, DB4, DB5, DB6, DB7);
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);


void setup() {
  lcd.begin(16, 2);
  randomSeed(analogRead(0)); 
  
  mostrarBienvenida();
  delay(2000);
  
  mostrarInicioJuego();
  delay(2000);
  
  mostrarFinJuego();
  delay(2000);
  
  int puntajeAleatorio = random(10, 500); 
  mostrarPuntuacion(puntajeAleatorio);
}

void loop() {
}

void mostrarBienvenida() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Bienvenido");
  lcd.setCursor(1, 1);
  lcd.print("Cargando juego");
}

void mostrarInicioJuego() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Preparate");
  lcd.setCursor(2, 1);
  lcd.print("Va a empezar");
}

void mostrarFinJuego() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Juego terminado");
  lcd.setCursor(1, 1);
  lcd.print("Fin del Juego");
}

void mostrarPuntuacion(int puntaje) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Puntuacion total:");
  lcd.setCursor(0, 1);
  lcd.print("Puntos: ");
  lcd.print(puntaje);
}