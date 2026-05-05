// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);//rojo
  pinMode(3, OUTPUT);//azul
  pinMode(4, OUTPUT);//verde
  
  pinMode(5, OUTPUT);//azul
  pinMode(6, OUTPUT);//rojo
  pinMode(7, OUTPUT);//verde
}

void loop()
{
  //pimero
  
  //rojo
  
  digitalWrite( 2 , HIGH); //rojo
  
  delay(1000);
  
  //cian
  
  digitalWrite( 2 , LOW ); //rojo
  digitalWrite( 3 , HIGH ); //azul
  digitalWrite( 4 , HIGH );//verde
  
  delay(1000);
  
  //verde
  
  digitalWrite( 3 , LOW ); //azul
  digitalWrite( 4 , HIGH ); //verde
  
  delay(1000);
  
  //magenta
  
  digitalWrite( 4 , LOW ); //verde
  digitalWrite( 2 , HIGH );//rojo
  digitalWrite( 3 , HIGH ); //azul
  
  delay(1000);
  
  //azul
  
  digitalWrite( 2 , LOW ); //rojo
  digitalWrite( 3 , HIGH ); //azul
  
  delay(1000);
  //blanco
  
  digitalWrite( 2 , HIGH ); //rojo
  digitalWrite( 3 , HIGH ); //azul
  digitalWrite( 4 , HIGH ); //verde
  
  delay(1000);
  //amarillo
  
  digitalWrite( 3 , LOW ); 
  digitalWrite( 2 , HIGH ); 
  digitalWrite( 4 , HIGH ); 
  
  delay(1000);
  
  digitalWrite( 2 , LOW ); 
  digitalWrite( 3 , LOW ); 
  digitalWrite( 4 , LOW ); 
  
  delay(1000);
  
    //segundo
  
  digitalWrite( 6 , HIGH); //rojo
  
  delay(1000);
  
  //cian
  
  digitalWrite( 6 , LOW );//rojo
  digitalWrite( 5 , HIGH ); //azul
  digitalWrite( 7 , HIGH ); //verde
  
  delay(1000);
  
  //verde
  
  digitalWrite( 7 , LOW ); //verde
  digitalWrite( 5 , HIGH );//azul
  
  delay(1000);
  
  //magenta
  
  digitalWrite( 7 , LOW );//verde
  digitalWrite( 5 , HIGH );//azul
  digitalWrite( 6 , HIGH );//rojo
  
  delay(1000);
  
  //azul
 
  digitalWrite( 6 , LOW );//ROJO
  digitalWrite( 5 , HIGH );//AZUL
  
  delay(1000);
  
  //blanco
  
  digitalWrite( 5 , HIGH );
  digitalWrite( 6 , HIGH );
  digitalWrite( 7 , HIGH );
  
  delay(1000);
 
  //amarillo
  
  digitalWrite( 5 , LOW );
  digitalWrite( 6 , HIGH );
  digitalWrite( 7 , HIGH );
  
  delay(1000);
  
  digitalWrite( 5 , LOW );
  digitalWrite( 6 , LOW );
}