#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 12

#define POT A0
#define BOTON 2

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int efecto = 0;
bool estadoBoton = 0;
bool ultimoEstado = 0;

void setup() {
  pixels.begin();
  pixels.clear();
  pixels.show();

  pinMode( 2 , INPUT_PULLUP );
}

void loop() {

  estadoBoton = digitalRead(2);

  if (estadoBoton == LOW && ultimoEstado == HIGH) {
    efecto++;

    if (efecto > 2) {
      efecto = 0;
    }

    delay(200);
  }

  ultimoEstado = estadoBoton;

  switch (efecto) {

    case 0:
      efecto1();
      break;

    case 1:
      efecto2();
      break;

    case 2:
      efecto3();
      break;
  }
}

int velocidad() {
  int valor = analogRead(POT);
  return map(valor, 0, 1023, 50, 1000);
}

void apagarTodo() {
  pixels.clear();
  pixels.show();
}

void efecto1() {

  uint32_t colores[] = {
    pixels.Color(255, 0, 0),
    pixels.Color(0, 255, 0),
    pixels.Color(0, 0, 255),
    pixels.Color(255, 255, 0),
    pixels.Color(255, 0, 255),
    pixels.Color(0, 255, 255),
    pixels.Color(255, 100, 0),
    pixels.Color(100, 0, 255),
    pixels.Color(255, 255, 255),
    pixels.Color(0, 150, 50),
    pixels.Color(150, 50, 0),
    pixels.Color(50, 50, 255)
  };

  for (int i = 0; i < NUMPIXELS; i++) {

    apagarTodo();

    pixels.setPixelColor(i, colores[i]);
    pixels.show();

    delay(velocidad());
  }

  apagarTodo();
  delay(1000);
}

void efecto2() {

  for (int i = 0; i < NUMPIXELS; i++) {

    apagarTodo();

    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();

    delay(velocidad());
  }

  for (int i = NUMPIXELS - 1; i >= 0; i--) {

    apagarTodo();

    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();

    delay(velocidad());
  }

  apagarTodo();
  delay(1000);
}

void efecto3() {

  for (int i = 0; i < NUMPIXELS; i++) {

    if (i % 2 == 0) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(i, 0);
    }
  }

  pixels.show();
  delay(500);

  apagarTodo();

  for (int i = 0; i < NUMPIXELS; i++) {

    if (i % 2 != 0) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    } else {
      pixels.setPixelColor(i, 0);
    }
  }

  pixels.show();
  delay(500);

  apagarTodo();

  for (int i = 0; i < NUMPIXELS; i++) {

    if (random(0, 2) == 1) {
      pixels.setPixelColor(i, pixels.Color(random(0,255), random(0,255), random(0,255)));
    }
  }

  pixels.show();
  delay(velocidad());

  apagarTodo();
  delay(1000);
}
