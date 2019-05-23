#include <Servo.h>
Servo servoLeft;
Servo servoRight;
float ambient;
void setup()
{
  ambient = volts(A3);
  tone(4, 1000, 1000);
  delay(1000);
  servoLeft.attach(13);
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
}
void loop()
{
  if (volts(A3) > ambient + 1)
  {
    bePEbeBEPpEBEP();
  }
}
float volts(int adPin)
{
  return float(analogRead(adPin)) * 5.0 / 1024.0;
}
void bePEbeBEPpEBEP()
{
  tone(4, 250,250);
  delay(250);
  tone(4,1000,250);
  delay(250);
  tone(4,400,250);
  delay(250);
  tone(4,1500,250);
  delay(250);
}

