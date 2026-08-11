#include <Adafruit_NeoPixel.h>

#define PIN_NEOPIXEL 6
#define CANT_LEDS 8

#define BOTON 2
#define BUZZER 9

Adafruit_NeoPixel leds(CANT_LEDS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

int dado1 = 0;
int dado2 = 0;

int estadoBoton;
int estadoAnterior = HIGH;


void mostrarDado(int numero, int inicio)
{

  leds.setPixelColor(inicio, 0);
  leds.setPixelColor(inicio + 1, 0);
  leds.setPixelColor(inicio + 2, 0);
  leds.setPixelColor(inicio + 3, 0);

  if (numero == 1)
  {
    leds.setPixelColor(inicio, leds.Color(255, 255, 255));
  }

  if (numero == 2)
  {
    leds.setPixelColor(inicio + 1, leds.Color(255, 255, 255));
  }

  if (numero == 3)
  {
    leds.setPixelColor(inicio, leds.Color(255, 255, 255));
    leds.setPixelColor(inicio + 1, leds.Color(255, 255, 255));
  }

  if (numero == 4)
  {
    leds.setPixelColor(inicio + 2, leds.Color(255, 255, 255));
  }

  if (numero == 5)
  {
    leds.setPixelColor(inicio, leds.Color(255, 255, 255));
    leds.setPixelColor(inicio + 2, leds.Color(255, 255, 255));
  }

  if (numero == 6)
  {
    leds.setPixelColor(inicio + 1, leds.Color(255, 255, 255));
    leds.setPixelColor(inicio + 2, leds.Color(255, 255, 255));
  }
}


void mostrarDados(int numero1, int numero2)
{
  mostrarDado(numero1, 0);
  mostrarDado(numero2, 4);

  leds.show();
}

void apagarTodos()
{
  for (int i = 0; i < CANT_LEDS; i++)
  {
    leds.setPixelColor(i, 0);
  }

  leds.show();
}


void victoria()
{
  Serial.println("================================");
  Serial.println(" GANASTE!!!");
  Serial.println("================================");

  
  tone(BUZZER, 1000);

 
  for (int i = 0; i < 3; i++)
  {
  
    for (int j = 0; j < CANT_LEDS; j++)
    {
      leds.setPixelColor(j, leds.Color(255, 255, 255));
    }

    leds.show();
    delay(200);

   
    apagarTodos();

    delay(200);
  }

  noTone(BUZZER);
}

void setup()
{
  leds.begin();
  leds.show();

  pinMode(BOTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  randomSeed(analogRead(A0));

  apagarTodos();

  Serial.println("================================");
  Serial.println(" JUEGO DE DADOS");
  Serial.println("================================");
  Serial.println("Presiona el boton para tirar.");
}


void loop()
{
  estadoBoton = digitalRead(BOTON);


  if (estadoAnterior == HIGH && estadoBoton == LOW)
  {
    Serial.println();
    Serial.println("TIRANDO LOS DADOS...");

    for (int i = 0; i < 10; i++)
    {
      dado1 = random(1, 7);
      dado2 = random(1, 7);

      mostrarDados(dado1, dado2);

      delay(100);
    }

    dado1 = random(1, 7);
    dado2 = random(1, 7);

    mostrarDados(dado1, dado2);


    Serial.println("-------------------------------");

    Serial.print("Dado 1: ");
    Serial.println(dado1);

    Serial.print("Dado 2: ");
    Serial.println(dado2);

    Serial.print("Suma: ");
    Serial.println(dado1 + dado2);

    Serial.println("-------------------------------");

    if (dado1 + dado2 == 7)
    {
      victoria();
    }
    else
    {
      Serial.println("No ganaste. Intenta nuevamente.");
    }

    Serial.println();
    Serial.println("Presiona nuevamente el boton.");

    delay(300);
  }

  estadoAnterior = estadoBoton;
}
