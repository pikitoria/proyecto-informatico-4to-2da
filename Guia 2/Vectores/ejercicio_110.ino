int Vector[10]; 
int Buzz = 2;

void setup()
{
  pinMode(Buzz, OUTPUT);
  Serial.begin(9600);
  
  for (int i = 0; i < 10; i++) {
    Vector[i] = random(1, 11);
  }

  Serial.print("Vector: ");
  for (int i = 0; i < 10; i++) {
    Serial.print(Vector[i]);  
    Serial.println(" ");
  } 


  for (int i = 0; i < 10; i++) {
    if (Vector[i] == 5) {
      Serial.println("Numero 5");
      digitalWrite(Buzz, HIGH);
      delay(1000);
      digitalWrite(Buzz, LOW); 
      delay(1000);
    }
  }
}

void loop()
{

}