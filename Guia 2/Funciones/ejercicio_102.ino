const int TRIG = 11;
const int ECHO = 10;

float distancia() {
digitalWrite(TRIG, LOW);
delayMicroseconds(2);
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);

long tiempo = pulseIn(ECHO, HIGH, 30000);

if (tiempo == 0) {
return 0.00;
}

return tiempo * 0.0343 / 2;
}

void setup() {
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
Serial.begin(9600);
}

void loop() {
Serial.print(distancia());
Serial.println(" cm");
delay(500);
}