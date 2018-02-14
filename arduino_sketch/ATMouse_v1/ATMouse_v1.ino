
#include "Mouse.h"

// set pin numbers for the five buttons:
const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;
const int leftClickButton = 6;
const int rightClickButton = 7;
const int doubleClickButton = 8;
const int leftClickHoldButton = 9;
const int middleClickButton = A3;
const int wheelUpButton = 14;
const int wheelDownButton = 15;
const int middleClickHoldButton = 16;
const int speedButton = A0;
const int leftClickHoldLED = A1;
const int middleClickHoldLED = A2;
const int speedLED = 10;
const int speedLedValueLow = 30;
const int speedLedValueMid = 125;
const int speedLedValueHigh = 255;


unsigned long leftClickDebouncer = 0;
unsigned long rightClickDebouncer = 0;
unsigned long middleClickDebouncer = 0;
unsigned long doubleClickDebouncer = 0;
unsigned long leftClickHoldDebouncer = 0;
unsigned long middleClickHoldDebouncer = 0;
unsigned long speedDebouncer = 0;
bool isLeftClickHold = false;
bool isMiddleClickHold = false;

int speedValue = 1;


int range = 2;              // output range of X or Y movement; affects movement SPEED
int responseDelay = 10;     // response delay of the mouse, in ms


void setup() {
  // initialize the buttons' inputs:
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftClickButton, INPUT);

  pinMode(rightClickButton, INPUT);
  pinMode(doubleClickButton, INPUT);
  pinMode(leftClickHoldButton, INPUT);
  pinMode(middleClickButton, INPUT);
  pinMode(wheelUpButton, INPUT);
  pinMode(wheelDownButton, INPUT);
  pinMode(middleClickHoldButton, INPUT);

  pinMode(speedButton, INPUT);
  pinMode(leftClickHoldLED, OUTPUT);
  pinMode(middleClickHoldLED, OUTPUT);
  pinMode(speedLED, OUTPUT);


  //TODO poner flashes de LED para indicar inicializacion
  digitalWrite(leftClickHoldLED, LOW);
  digitalWrite(middleClickHoldLED, LOW);
  digitalWrite(speedLED, LOW);

  analogWrite(speedLED, speedLedValueLow);

  
  // initialize mouse control:
  Mouse.begin();
}

void loop() {
  // read the buttons:
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);
  int rightState = digitalRead(rightButton);
  int leftState = digitalRead(leftButton);
  int leftClickState = digitalRead(leftClickButton);

  int rightClickState = digitalRead(rightClickButton);
  int doubleClickState = digitalRead(doubleClickButton);
  int leftClickHoldState = digitalRead(leftClickHoldButton);
  int middleClickState = digitalRead(middleClickButton);
  int wheelUpState = digitalRead(wheelUpButton);
  int wheelDownState = digitalRead(wheelDownButton);
  int middleClickHoldState = digitalRead(middleClickHoldButton);
  int speedState = digitalRead(speedButton);



  // MOVEMENT
  // TODO el wheeldistance esta un poco demasiado rapido
  // calculate the movement distance based on the button states:
  int  xDistance = (rightState - leftState) * range;
  int  yDistance = ( downState - upState) * range;
  int  wheelDistance = ( wheelUpState - wheelDownState) ;

  // if X or Y is non-zero, move:
  if ((xDistance != 0) || (yDistance != 0) || wheelDistance != 0) {
    Mouse.move(xDistance, yDistance, wheelDistance);
  }
  

  //CLICKS

 // LEFT CLICK BUTTON
  if (leftClickState && leftClickDebouncer < millis()) {
     Mouse.press(MOUSE_LEFT);
     leftClickDebouncer = millis() + 10;
  } else if(!leftClickState && !isLeftClickHold){
     Mouse.release(MOUSE_LEFT);
  }
  
 // RIGHT CLICK BUTTON
  if (rightClickState && rightClickDebouncer < millis()) {
     Mouse.press(MOUSE_RIGHT);
     rightClickDebouncer = millis() + 10;
  } else if(!rightClickState){
     Mouse.release(MOUSE_RIGHT);
  }
 
  
 // DOUBLE LEFT CLICK
 if(doubleClickState && doubleClickDebouncer < millis()){
    Mouse.click(MOUSE_LEFT);
    delay(20);
    Mouse.click(MOUSE_LEFT);
    doubleClickDebouncer = millis() + 1000;
  } 

  
  // LEFT CLICK HOLD
  if(leftClickHoldState && leftClickHoldDebouncer < millis()){
    if(!isLeftClickHold){
      isLeftClickHold = true;
      Mouse.press(MOUSE_LEFT);
      digitalWrite(leftClickHoldLED, HIGH);
      leftClickHoldDebouncer = millis() + 1000;
    } else {
      isLeftClickHold = false;
      Mouse.release(MOUSE_LEFT);
      digitalWrite(leftClickHoldLED, LOW);
      leftClickHoldDebouncer = millis() + 1000;
    } 
  }

 // MIDDLE CLICK BUTTON
  if (middleClickState && middleClickDebouncer < millis()) {
     Mouse.click(MOUSE_MIDDLE);
     middleClickDebouncer = millis() + 200;
  }

  // MIDDLE CLICK HOLD
  if(middleClickHoldState && middleClickHoldDebouncer < millis()){
    if(!isMiddleClickHold){
      isMiddleClickHold = true;
      Mouse.press(MOUSE_MIDDLE);
      digitalWrite(middleClickHoldLED, HIGH);
      middleClickHoldDebouncer = millis() + 1000;
    } else {
      isMiddleClickHold = false;
      Mouse.release(MOUSE_MIDDLE);
      digitalWrite(middleClickHoldLED, LOW);
      middleClickHoldDebouncer = millis() + 1000;
    } 
  }

  // SPEED CONTROL
  if(speedState && speedDebouncer < millis()){
    switch (speedValue){
      case 1:
        speedValue = 2;
        range = 5;
        analogWrite(speedLED, speedLedValueMid);
        break;
      case 2:
        speedValue = 3;
        range = 7;
        digitalWrite(speedLED, HIGH);
        break;
      case 3:
        speedValue = 1;
        range = 2;
        analogWrite(speedLED, speedLedValueLow);
        break;
    }

    speedDebouncer = millis() + 300;
  }
  

  // a delay so the mouse doesn't move too fast:
  delay(responseDelay);
}
