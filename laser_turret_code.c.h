// BreakoutBros Mini Laser Turret Tutorial
// 2016

// Go to BreakoutBros.com to view wiring and step by step instructions


#include  // Include the Servo Library to control the servos

Servo xservo;  // create servo object to control the x direction servo
Servo yservo;  // create servo object to control the y direction servo

//*****************************************************************\\
//*****************************************************************\\
//                          STEP ONE
//*****************************************************************\\
//*****************************************************************\\

//Servo Variables
int pos = 0;       // variable to store the servo position
int XServoPin = 9; // Servo pin that will control X motion
int YServoPin = 8; // Servo pin that will control Y motion

//Joystick variables
int xposPin = A0;    // select the input pin for the potentiometer
int yposPin = A1;    // select the input pin for the potentiometer
int Xpos = 0;
int Ypos = 0;
int buttonPin = 7;
int buttonPress = 0;

//Lazer Variables
int lazerPin = 6;
//*****************************************************************\\
//*****************************************************************\\
//                          STEP TWO
//*****************************************************************\\
//*****************************************************************\\
void setup() {
  pinMode(lazerPin,OUTPUT);      //The lazer will be an output
  pinMode(buttonPin,INPUT);      //The buttonpress pin is an input
  digitalWrite(buttonPin,HIGH);  //This enables the Arduino pullup for this pin
  
  xservo.attach(XServoPin);  // attaches the servo on pin 9 to the servo object
  yservo.attach(YServoPin);  // attaches the servo on pin 8 to the servo object
}

void loop() {
//*****************************************************************\\
//*****************************************************************\\
//                          STEP THREE
//*****************************************************************\\
//*****************************************************************\\
  
  buttonPress = digitalRead(buttonPin); //Read the sate of the button
  if(buttonPress == LOW) // The button press is active low , so if it is pressed we will turn the lazer on
  {
    digitalWrite(lazerPin, HIGH); //Turn Lazer on
  }
  else
  {
    digitalWrite(lazerPin, LOW); // If it is not pressed, keep lazer off
  }

//*****************************************************************\\
//*****************************************************************\\
//                          STEP FOUR
//*****************************************************************\\
//*****************************************************************\\
 
  Xpos = analogRead(xposPin);     // read and store the x position location of the joystick
  Xpos = map(Xpos,0,1023,0,180);  //map the analog read x values to the 0-180 servo values
  Ypos = analogRead(yposPin);     // read and store the y position of the joystick
  Ypos = map(Ypos,0,1023,0,180);  //map the analog read y values to the 0-180 servo values
  xservo.write(Xpos);             // move the X Location servo to the x position the joystick is at
  yservo.write(Ypos);             // move the Y Location servo to the y position the joystick is at
  delay(50);                      // add in a slight delay to help with "jittering"
}
