#define Led_R 6
#define Led_A 4
#define Led_V 5
#define Led_r 2
#define Led_B 3
void setup()
{
  pinMode(Led_R, OUTPUT);
  pinMode(Led_A, OUTPUT);
  pinMode(Led_V, OUTPUT);
  pinMode(Led_r, OUTPUT);
  pinMode(Led_B, OUTPUT);
}

void loop()
{
  digitalWrite(Led_R,HIGH);//rojo
  digitalWrite(Led_A,LOW); //verde
  digitalWrite(Led_V,LOW); //amarillo
  digitalWrite(Led_B,HIGH);//blanco
  digitalWrite(Led_r,LOW);//ROJO
  
  delay(4000);
  
  digitalWrite(Led_R,LOW);//rojo
  digitalWrite(Led_A,HIGH);//amarillo
  digitalWrite(Led_V,LOW);//verde	
  digitalWrite(Led_B,LOW);//blanco 
  digitalWrite(Led_r,HIGH);//ROJO
 
  delay(4000);
  
  
  digitalWrite(Led_R,LOW);//rojo
  digitalWrite(Led_A,LOW);//marillo
  digitalWrite(Led_V,HIGH);//verde
  digitalWrite(Led_B,LOW);//blanco 
  digitalWrite(Led_r,HIGH);//ROJO

  delay(4000);
  
  digitalWrite(Led_R,LOW);//rojo
  digitalWrite(Led_A,HIGH);//amarillo
  digitalWrite(Led_V,LOW);//verde
  digitalWrite(Led_B,LOW);//blanco 
  
  delay(4000);
  
  
  
}