//plays national anthem
const int songLength = 23;
const int buzzer = 4;
void setup()
{
  pinMode(buzzer, OUTPUT);
}
int tempo = 250;
char notes[] = "gecegCEDCefgggEDCbabCCg";
int beats[] = {1, 1, 2, 2, 2, 4, 1, 1, 2, 2, 2, 4, 1, 1, 3, 1, 2, 4, 1, 1, 2, 2, 2};
void nationalAnthem()
{
  int songLength = 25;
  int duration;
  for (int i = 0; i < songLength; i++)
  {
    duration = tempo * beats[i];
    if (notes[i] == ' ')
    {
      delay(duration);
    }
    else
    {
      tone(buzzer, frequency(notes[i]), duration);
      delay(duration);
    }

  }

}
int frequency(char note)
{
  const int numNotes = 14;
  char names[] = {'z', 'x', 'c', 'd', 'e', 'f', 'g', 'q', 'a', 'b', 'C', 'D', 'E', 'G', 'A' };
  int frequencies[] = {247, 130, 262, 294, 330, 370, 392, 415, 440, 494, 523, 587, 659, 784, 880 };
  for (int i = 0; i < numNotes; i++)
  {
    if (note == names[i])
    {
      return frequencies[i];
    }
  }
  return (0);
}

void loop()
{
  nationalAnthem();
}
