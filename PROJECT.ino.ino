const int red1 = 2;
const int blue1 = 3;
const int green = 4;
const int yellow = 5;
const int red2 = 6;
const int blue2 = 7;
const int button = 11;
const int swiitch = 12;
const int photoresistor = 0;
int lightVal;
int lightCal;
void setup() {
 int x = 2; 
 for (x=2;x<8; x++)
 {
  pinMode (x, OUTPUT);
 }
 pinMode (button, INPUT);
 pinMode (swiitch, INPUT);
 pinMode (photoresistor, INPUT);
 lightCal = analogRead(photoresistor);
}

void loop() {
  int switchState;
  switchState = digitalRead(swiitch);
  if (switchState == HIGH)
  {
    int buttonState;
    buttonState = digitalRead(button);
    digitalWrite(green, HIGH);
    if (buttonState == LOW)
    {
      for(int x=4;x<6;x++)
      {
        digitalWrite(x, LOW);
        digitalWrite(x+1,HIGH);
        delay(1000);
      }
      delay(2000);
      digitalWrite(red2,LOW);
    }
  }
  else 
  {
    digitalWrite(green, LOW);
    lightVal = analogRead(photoresistor);
    if (lightVal < lightCal - 50)
    {
      for(int x=2; x<8; x=x+2)
      {
        digitalWrite(x,HIGH);
        digitalWrite(x+1,HIGH);
        delay(1000);
      }
      
      for (int x=2; x<8;x++)
      {
        digitalWrite(x, LOW);
        delay(500);
      }
    }
    else{
      
    }
  }

}
