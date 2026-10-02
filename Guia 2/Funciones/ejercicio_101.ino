int Buzzer = 2;

void setup() {
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  melodia1();   
  delay(200);

  melodia2();   
  delay(2000);

  melodia3(); 
  delay(200);
}

void melodia1() {
  for (int i = 0; i < 2; i++) {
    tone(Buzzer,2200);
    delay(500);
    noTone(Buzzer);
    delay(500);
  }
}


void melodia2() {
  for (int i = 0; i < 2; i++) {
    tone(Buzzer,3000);
    delay(200);
    noTone(Buzzer);
    delay(200);
  }
}

void melodia3() {
  for (int i = 0; i < 4; i++) {
    tone(Buzzer,1000);
    delay(1000);
    noTone(Buzzer);
    delay(1000);
  }
  
}