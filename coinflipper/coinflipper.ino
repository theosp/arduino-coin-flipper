/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int button = 8;
int action_performed = 0;
int pressed = 0;
int state = 0;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  pinMode(button, INPUT_PULLUP);
  
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Serial Ready");
}

void loop()
{
  if (digitalRead(button) == LOW) {
    pressed = 1;
  } else  {
    pressed = 0;
    action_performed = 0;
  }

  if (pressed && !action_performed) {
    // state = (state + 1) % 2; sequential
    state = random(2);
    
    setColor(0, 0, 0);  // yellow
    delay(1000);
    
    if (state == 0) {
      setColor(255, 0, 0);  // red
    } else {
      setColor(0, 255, 0);  // green
    }

    action_performed = 1;
  }
}

void determinationDelay() {

}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
