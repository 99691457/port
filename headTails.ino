long randNumber; String result; int headCount; int tailCount; void setup() {Serial.begin(9600); randomSeed(analogRead(0));} void loop() {randNumber = random(2); if (randNumber == 1){ result= "Heads"; headCount += 1;} else{ result = "Tails"; tailCount += 1;} Serial.println(result); if (headCount == 100){ Serial.println("Heads wins"); Serial.print("Heads won by "); Serial.println(headCount - tailCount); delay(10000); tailCount = 0; headCount = 0; } if (tailCount == 100){ Serial.println("Tails wins"); Serial.print("Tails won by "); Serial.println(tailCount - headCount); delay(5000); tailCount = 0; headCount = 0;} delay(15);}
