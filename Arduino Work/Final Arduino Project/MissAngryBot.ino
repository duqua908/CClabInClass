

int redPin = 9;
int greenPin = 11;
int bluePin = 10;
int buzzerPin = 7;

int potPin = 1;
int sensorPin = 0;

long green=0xFF0000;
long red=0x00FF00;
long blue=0x000080;

int band= 10;

void setup()
{
  pinMode(potPin, INPUT);
  pinMode(sensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  int GAR = analogRead(sensorPin);
  int pot = analogRead(potPin);
  if (GAR > (pot + band))
 {
     setColor(red);
     beep();
 } else if (GAR < (pot - band))
     setColor(blue);
 else
     setColor(green);
}

void setColor(long rgb)
{
    int red = rgb >> 16;
    int green = (rgb >> 8) & 0xFF;
    int blue = rgb & 0xFF;
    analogWrite(redPin, 255 - red);
    analogWrite(greenPin, 255 - green);
    analogWrite(bluePin, 255 - blue);
}

void beep()
{
     for (int i=0; i < 1000; i++)
 {
      digitalWrite(buzzerPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(buzzerPin, LOW);
      delayMicroseconds(100);
 }
}
