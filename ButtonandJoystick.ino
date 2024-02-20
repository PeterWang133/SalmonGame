#include <Keyboard.h>
#include <avr/sleep.h>
// Pin setting for the four buttons
const int button1 = 1;
const int button2 = 2;
const int button3 = 3;
const int button4 = 4;

// Pin setting for the joystick
const int left = 6;
const int up = 7;
const int right = 8;
const int down = 9;

int button1State=0;
int button2State=0;
int button3State=0;
int button4State=0;

int buttonStateLeft = 0;
int previousButtonStateLeft=0;

int buttonStateUp = 0;
int previousButtonStateUp=0;

int buttonStateRight = 0;
int previousButtonStateRight=0;

int buttonStateDown = 0;
int previousButtonStateDown=0;

int timer = 0;
int previousTime=0;


void setup() {
  Keyboard.begin(); // Keyboard input
  sleep_disable();
  pinMode(button1, INPUT_PULLUP); // Sets button1 to pin1
  pinMode(button2,INPUT_PULLUP); // Sets button2 to pin2
  pinMode(button3,INPUT_PULLUP); // Sets button3 to pin3
  pinMode(button4,INPUT_PULLUP); // Sets button4 to pin4
  pinMode(left,INPUT_PULLUP); // Sets right button as left and to pin6
  pinMode(right,INPUT_PULLUP); // Sets left button as right and to pin7
  pinMode(up,INPUT_PULLUP); // Sets bottom button as up and to pin8
  pinMode(down,INPUT_PULLUP); // Sets top button as down and to pin9
  Serial.begin(9600);
}

void loop() {
  timer=millis(); // Starts timing
  sleep_disable(); // Disable sleep mode
  button1State=digitalRead(button1); // Reads the button state of button1
  button2State=digitalRead(button2); // Reads button2 button state
  button3State=digitalRead(button3); // Reads state of button3
  button4State=digitalRead(button4); // Reads state of button4

  // IF the button reading is high and 0.2 s has passed since last recorded time
  if(button1State==HIGH&&timer-previousTime>200){
    // Press key 'z'
    Keyboard.press('z');
    // Release the key
    Keyboard.releaseAll();
    // Records the time that user made input
    previousTime=timer;
  // ENDIF
  }
  // IF the button reading is high and 0.2 s has passed since last recorded time
  if(button2State==HIGH&&timer-previousTime>200){
    // Press key 'x'
    Keyboard.press('x');
    // Release the key
    Keyboard.releaseAll();
    // Records the time that user made input
    previousTime=timer;
  // ENDIF
  }
  // IF the button reading is high and 0.2 s has passed since last recorded time
  if(button3State==HIGH&&timer-previousTime>200){
    // Press key 'v'
    Keyboard.press('v');
    // Release the key
    Keyboard.releaseAll();
    // Records the time that user made input
    previousTime=timer;
  // ENDIF
  }
  // IF the button reading is high and 0.2 s has passed since last recorded time
  if(button4State==HIGH&&timer-previousTime>200){
    // Press key 'b'
    Keyboard.press('b');
    // Release the key
    Keyboard.releaseAll();
    // Records the time that user made input
    previousTime=timer;
  // ENDIF
  }
   buttonStateLeft=digitalRead(left); // Reads the right button state
  buttonStateUp=digitalRead(up); // reads the button button state
  buttonStateRight=digitalRead(right); // reads the left button state
  buttonStateDown=digitalRead(down); // reads the tip button state
  // WHILE the button reading is low and 0.05 s has passed since last recorded time
  while(buttonStateLeft==LOW&&previousButtonStateLeft!=buttonStateLeft&&timer-previousTime>50){
    // Press key 'a'
    Keyboard.press('a');
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is low and 0.05 s has passed since last recorded time
  while(buttonStateUp==LOW&&previousButtonStateUp!=buttonStateUp&&timer-previousTime>50){
    // Press key 'w'
    Keyboard.press('w');
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is low and 0.05 s has passed since last recorded time
  while(buttonStateRight==LOW&&previousButtonStateRight!=buttonStateRight&&timer-previousTime>50){
    // Press key 'd'
    Keyboard.press('d');
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is low and 0.05 s has passed since last recorded time
  while(buttonStateDown==LOW&&previousButtonStateDown!=buttonStateDown&&timer-previousTime>50){
    // Press key 'd'
    Keyboard.press('s');
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is high and 0.05 s has passed since last recorded time
  while(buttonStateDown==HIGH&&previousButtonStateDown!=buttonStateDown&&timer-previousTime>50){
    // Release all the key
    Keyboard.releaseAll();
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is high and 0.05 s has passed since last recorded time
  while(buttonStateUp==HIGH&&previousButtonStateUp!=buttonStateUp&&timer-previousTime>50){
    // Release all the key
    Keyboard.releaseAll();
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is high and 0.05 s has passed since last recorded time
  while(buttonStateLeft==HIGH&&previousButtonStateLeft!=buttonStateLeft&&timer-previousTime>50){
    // Release all the key
    Keyboard.releaseAll();
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
  // WHILE the button reading is high and 0.05 s has passed since last recorded time
  while(buttonStateRight==HIGH&&previousButtonStateRight!=buttonStateRight&&timer-previousTime>50){
    // Release all the key
    Keyboard.releaseAll();
    // Records the time when user made input
    previousTime=timer;
  // END WHILE
  }
    // Recprds the last buttonstate of each button of the joystick
      previousButtonStateLeft=buttonStateLeft;
      previousButtonStateUp=buttonStateUp;
      previousButtonStateRight=buttonStateRight;
      previousButtonStateDown=buttonStateDown;
}
