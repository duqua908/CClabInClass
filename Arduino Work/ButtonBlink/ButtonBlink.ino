
//define led and button pins, as well as the state of the button.
int led = 13;
int buttonPin = 7;
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
// initialize the pinModes
pinMode(led,OUTPUT);
pinMode(buttonPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop(){
  //read the button
  buttonState = digitalRead(buttonPin);
  // Perform different actions depending on the state of the button
  if(buttonState == HIGH){
    digitalWrite(led, HIGH); //turn the LED on (High is the voltage level)
    delay(1000);  //wait for a second
  } else{
    digitalWrite(led, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);
  }
}

