#define r 11
#define g 10
#define b 9
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  int L1[] = {122, 234, 21};
  int L2[] = {33, 53, 155};
  int L3[] = {200, 255, 12};
  int r1 = 122;
  int r2 = 33;
  int r3 = 200;
  int g1 = 234;
  int g2 = 53;
  int g3 = 255;
  int b1 = 21;
  int b2 = 155;
  int b3 = 12;
  for (int i = 0; i < 3; i++)
  {
    analogWrite(r, r1);
    analogWrite(g, g1);
    analogWrite(b, b1);
    delay(500);
    analogWrite(r, r2);
    analogWrite(g, g2);
    analogWrite(b, b2);
    delay(500);
    analogWrite(r, r3);
    analogWrite(g, g3);
    analogWrite(b, b3);
    delay(500);
  }
}