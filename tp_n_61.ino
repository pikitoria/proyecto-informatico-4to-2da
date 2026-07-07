int tempPin = A0;
int pirPin = 2;

int motorPin = 9;
int lamparaPin = 10;

float temperatura;
int valorTemp;
int pwm;

void setup()
{
  pinMode(pirPin, INPUT);

  pinMode(motorPin, OUTPUT);
  pinMode(lamparaPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  valorTemp = analogRead(tempPin);

  temperatura = ((valorTemp * 5.0) / 1023.0 - 0.5) * 100;

  int movimiento = digitalRead(pirPin);
  pwm = map(temperatura, 15, 50, 50, 255);

  if (temperatura > 50)
  {
    analogWrite(motorPin, 255);
  }
  else
  {
    analogWrite(motorPin, 0);

    if (movimiento == HIGH)
    {
      digitalWrite(lamparaPin, HIGH);

      if (temperatura <= 15)
      {
        pwm = 50;
      }
      
      else if (temperatura == 30)
      {
        pwm = 150;
      }
      
      else if (temperatura >= 50)
      {
        pwm = 255;
      }
      

      analogWrite(motorPin, pwm);
    }
    else
    {
      digitalWrite(lamparaPin, LOW);
      analogWrite(motorPin, 0);
    }
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" C - Movimiento: ");
  Serial.println(movimiento);

  delay(500);
}