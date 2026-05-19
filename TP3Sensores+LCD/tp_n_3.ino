#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tempPin = A0;
int ldrPin = A1;

int pirPin = 7;

int trigPin = 8;
int echoPin = 9;

int buzzer = 10;

int ledRojo = 6;
int ledVerde = 13;
int ledAzul = A2;

float temperatura;
int luz;
int movimiento;
float distancia;

void setup() {

  pinMode(7, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, INPUT);

  pinMode(10, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A2, OUTPUT);

  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop() {

  int valorTemp = analogRead(A0);

  float voltaje = valorTemp * 5.0 / 1023.0;

  temperatura = (voltaje - 0.5) * 100.0;

  luz = analogRead(ldrPin);

  int porcentajeLuz = map(luz, 0, 1023, 0, 100);

  movimiento = digitalRead(7);

  digitalWrite(8, LOW);
  delayMicroseconds(2);

  digitalWrite(8, HIGH);
  delayMicroseconds(10);

  digitalWrite(8, LOW);

  long duracion = pulseIn(9, HIGH);

  distancia = duracion * 0.034 / 2;

  digitalWrite(6, LOW);
  digitalWrite(13, LOW);
  digitalWrite(A2, LOW);

  noTone(buzzer);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);

  lcd.print(" L:");
  lcd.print(porcentajeLuz);

  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.print(distancia);

  Serial.print("Temp: ");
  Serial.println(temperatura);

  Serial.print("Luz: ");
  Serial.println(porcentajeLuz);

  Serial.print("Distancia: ");
  Serial.println(distancia);

  Serial.print("Movimiento: ");
  Serial.println(movimiento);

  if (movimiento == HIGH) {

    digitalWrite(13, HIGH);

    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
  }

  if (temperatura > 39) {

    digitalWrite(6, HIGH);

    tone(buzzer, 1500);
    delay(300);
    noTone(buzzer);
  }

  if (distancia < 20) {

    digitalWrite(6, HIGH);

    tone(buzzer, 2000);
    delay(500);
    noTone(10);
  }

  if (porcentajeLuz < 5) {

    digitalWrite(A0, HIGH);
  }

  delay(1000);
}