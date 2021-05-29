#include "header.h"

States current_State = {LOW,LOW,LOW};
States last_States = {HIGH,HIGH,HIGH};

RGB_COLOR Color = {0,0,0,0}; 

void setup(){
  Serial.begin(9600);

  pinMode(PLUS_BUTTON,INPUT_PULLUP);
  pinMode(MINUS_BUTTON,INPUT_PULLUP);
  pinMode(COLOR_SELECTOR_BUTTON,INPUT_PULLUP);

  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  delay(1000);

  start();
}

/*
* Start up function to show that all colors are working
*/
void start(){

  RGB_Lighter(255,0,0);
  delay(2000);
  
  RGB_Lighter(0,255,0);
  delay(2000);

  RGB_Lighter(0,0,255);
  delay(2000);
}

/*
* Function to read a selected button
* @param int button represents the button to debounce
* @return int
*/
int16_t button_Reader(uint16_t button){
 
  int16_t state = digitalRead(button);
  delay(10);
  if(digitalRead(button) != state){
    state = digitalRead(button);
  }

  return state;
}

/*
* Function to light up RGB Led based upon values from input
* @param int blueColor for the amount for the blue color
* @param int redColor for the amount for the red color
* @param int greenColor for the amount for the green color
*/
void RGB_Lighter(uint32_t blueColor, uint32_t redColor, uint32_t greenColor){
  digitalWrite(BLUE_PIN,blueColor);
  digitalWrite(RED_PIN,redColor);
  digitalWrite(GREEN_PIN, greenColor);
}

void loop(){

current_State.plus =  button_Reader(PLUS_BUTTON);
current_State.minus = button_Reader(MINUS_BUTTON);
current_State.ColorSelection = button_Reader(COLOR_SELECTOR_BUTTON);

if(last_States.ColorSelection == LOW && current_State.plus == HIGH){
  Color.colorSelector++;

  if(Color.colorSelector>MAX_NUMBER_OF_COLORS){
    Color.colorSelector = START_COLOR;
  }

     switch (Color.colorSelector)
    {
      case 1:
        Serial.println("Selected blue color");
        RGB_Lighter(255,0,0);
        delay(COLOR_DELAY);
        break;
      case 2:
        Serial.println("Selected green color!");
        RGB_Lighter(0,0,255);
        delay(COLOR_DELAY);
        break;
      case 3:
        Serial.println("Selected red color!");
        RGB_Lighter(0,255,0);
        delay(COLOR_DELAY);
        break;
    }
}

if(last_States.plus == LOW && current_State.plus == HIGH){
    switch (Color.colorSelector)
    {
      case 1:
        Color.blue +=51;
        Serial.print("BLUE: "); Serial.println(Color.blue);
        break;
      case 2:
        Color.green +=51;
        Serial.print("GREEN: "); Serial.println(Color.green);
        break;
      case 3:
        Color.red +=51;
        Serial.print("RED: "); Serial.println(Color.red);
        break;
    }

    if(Color.red>255){
      Color.red = 0;
      Serial.print("NEW RED: "); Serial.println(Color.red);
    }
    if(Color.blue>255){
      Color.blue = 0;
      Serial.print("NEW BLUE: "); Serial.println(Color.blue);
    }
    if(Color.green>255){
      Color.green = 0;
      Serial.print("NEW GREEN: "); Serial.println(Color.green);
    }
}

if(last_States.minus == LOW && current_State.plus == HIGH){
      switch (Color.colorSelector)
    {
      case 1:
        Color.blue -=51;
        Serial.print("BLUE: "); Serial.println(Color.blue);
        break;
      case 2:
        Color.green -=51;
        Serial.print("GREEN: "); Serial.println(Color.green);
        break;
      case 3:
        Color.red -=51;
        Serial.print("RED: "); Serial.println(Color.red);
        break;
    }

    if(Color.red<0){
      Color.red = 255;
      Serial.print("NEW RED: "); Serial.println(Color.red);
    }
    if(Color.blue<0){
      Color.blue = 255;
      Serial.print("NEW BLUE: "); Serial.println(Color.blue);
    }
    if(Color.green<0){
      Color.green = 255;
      Serial.print("NEW GREEN: "); Serial.println(Color.green);
    }
}

RGB_Lighter(Color.blue,Color.red,Color.green);

last_States.plus = current_State.plus;
last_States.minus = current_State.minus;
last_States.ColorSelection = current_State.ColorSelection;
}