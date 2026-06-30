#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

#define PIN_NEOPIXEL 6
#define CANT_LEDS 6
#define PIN_LDR A0
#define PIN_BOTON 7

//#define PRUEBAS

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_NeoPixel tira(CANT_LEDS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

bool sistema = true;
bool estadoAnterior = HIGH;

void setup()
{
  pinMode(PIN_BOTON, INPUT_PULLUP);

  Serial.begin(9600);

  lcd.begin(16, 2);

  tira.begin();
  tira.show();
}

void loop()
{
  bool lecturaBoton = digitalRead(PIN_BOTON);

  if (estadoAnterior == HIGH && lecturaBoton == LOW)
  {
    sistema = !sistema;
    delay(200);
  }

  estadoAnterior = lecturaBoton;

  int sensor = analogRead(PIN_LDR);

  int porcentaje = map(sensor, 0, 1023, 0, 100);
  porcentaje = constrain(porcentaje, 0, 100);

  int leds = map(porcentaje, 0, 100, 0, 6);

  String color;

  if (porcentaje <= 30)
    color = "VERDE";
  else if (porcentaje <= 70)
    color = "AMARILLO";
  else
    color = "ROJO";

#ifdef PRUEBAS
  Serial.print("Sensor: ");
  Serial.print(sensor);
  Serial.print(" Porcentaje: ");
  Serial.print(porcentaje);
  Serial.print("% N Led: ");
  Serial.print(leds);
  Serial.print(" Color: ");
  Serial.println(color);
#endif

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(porcentaje);
  lcd.print("%");

  lcd.setCursor(0, 1);

  if (sistema)
    lcd.print("PRENDIDO");
  else
    lcd.print("APAGADO");

  lcd.setCursor(11, 1);
  lcd.print(color);

  if (sistema)
  {
    for (int i = 0; i < CANT_LEDS; i++)
    {
      if (i < leds)
      {
        switch (i)
        {
          case 0:
          case 1:
            tira.setPixelColor(i, tira.Color(0, 255, 0));
            break;

          case 2:
          case 3:
            tira.setPixelColor(i, tira.Color(255, 255, 0));
            break;

          case 4:
          case 5:
            tira.setPixelColor(i, tira.Color(255, 0, 0));
            break;
        }
      }
      else
      {
        tira.setPixelColor(i, 0);
      }
    }
  }
  else
  {
    for (int i = 0; i < CANT_LEDS; i++)
    {
      tira.setPixelColor(i, 0);
    }
  }

  tira.show();

  delay(200);
}
  