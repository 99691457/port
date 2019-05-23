
#include <Servo.h> // Include servo library
Servo servoLeft; // Declare left and right servos
Servo servoRight;



void setup() // Built-in initialization block
{
  Serial.begin(9600);
  pinMode(10, INPUT); pinMode(9, OUTPUT); // Left IR LED & Receiver
  pinMode(3, INPUT); pinMode(2, OUTPUT); // Right IR LED & Receiver
  tone(4, 3000, 1000); // Play tone for 1 second
  delay(1000); // Delay to finish tone
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
}
void loop() // Main loop auto-repeats
{
  int irLeft = irDetect(9, 10, 38000); // Check for object on left
  int irRight = irDetect(2, 3, 38000); // Check for object on right
  if ((irLeft == 0) && (irRight == 0)) // Both sides see table surface
  {
    maneuver(200, 200, 20); // Forward 20 milliseconds
    Serial.println("forward");
  }
  else 
  {
    maneuver(-200, -200, 250);
    delay(250);// Backward 250 ms before retry
    maneuver(200, -200, 250);
    delay(250);
  }
}
int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8); // IRLED 38 kHz for at least 1 ms
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
  delay(1); // Down time before recheck
  return ir; // Return 1 no detect, 0 detect
}
void maneuver(int speedLeft, int speedRight, int msTime)
{
  // speedLeft, speedRight ranges: Backward Linear Stop Linear Forward
  // -200 -100....0....100 200
  servoLeft.writeMicroseconds(1500 + speedLeft); // Left servo speed
  servoRight.writeMicroseconds(1500 - speedRight); // Right servo speed
  if (msTime == -1) // If msTime = -1
  {
    servoLeft.detach();
  }  
  delay(msTime);}
