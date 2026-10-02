const int TRIG = 12;
const int ECHO = 10;

const int ROJO = 6;
const int VERDE = 5;
const int AZUL = 3;

float distancia() {
digitalWrite(TRIG, LOW);
delayMicroseconds(2);
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);

long tiempo = pulseIn(ECHO, HIGH, 30000);

if (tiempo == 0) {
return 0;
}

return tiempo * 0.0343 / 2;
}

void setup() {
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);

pinMode(ROJO, OUTPUT);
pinMode(VERDE, OUTPUT);
pinMode(AZUL, OUTPUT);

Serial.begin(9600);
}

void loop() {
float cm = distancia();

Serial.print(cm);
Serial.println(" cm");

if (cm > 0 && cm < 100) {
analogWrite(ROJO, 255);
analogWrite(VERDE, 0);
analogWrite(AZUL, 0);
} else {
analogWrite(ROJO, 0);
analogWrite(VERDE, 0);
analogWrite(AZUL, 0);
}

delay(500);
}