const int led1 = 12;
const int led2 = 13;

int sec1[] = {1, 0, 0, 1, 1, 0, 1, 1};
int sec2[] = {0, 1, 0, 1, 0, 0, 1, 1};
int tam = 8;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  for (int i = 0; i < tam; i++) {
    digitalWrite(led1, sec1[i]);
    digitalWrite(led2, sec2[i]);
    delay(500);
  }
}