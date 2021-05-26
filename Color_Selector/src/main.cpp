#include <Arduino.h>
#include "header.h"

int plusState = HIGH;
int minusState = HIGH;
int colorSelectorState = HIGH;

int plusLastState = LOW;
int minusLastState = LOW;
int colorSelectorLastState = LOW;

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
* Start up function to show that all functions are working
*/
void start(){

  Color_Light(255,0,0);
  delay(2000);
  
  Color_Light(0,255,0);
  delay(2000);

  Color_Light(0,0,255);
  delay(2000);
}

/*
* Function to light up RGB Led based upon values 
* from input
*/
void Color_Light(int blueColor, int redColor, int greenColor){
/*
  digitalWrite(BLUE_PIN,redColor);
  digitalWrite(RED_PIN,greenColor);
  digitalWrite(GREEN_PIN,blueColor);
*/

  digitalWrite(BLUE_PIN,blueColor);
  digitalWrite(RED_PIN,redColor);
  digitalWrite(GREEN_PIN, greenColor);
  
}

void loop(){
plusState = digitalRead(PLUS_BUTTON);
minusState = digitalRead(MINUS_BUTTON);
colorSelectorState = digitalRead(COLOR_SELECTOR_BUTTON);


if(colorSelectorLastState == LOW && colorSelectorState == HIGH){
  Color.colorSelector++;

  if(Color.colorSelector>3){
    Color.colorSelector = 1;
  }

     switch (Color.colorSelector)
    {
      case 1:
        Serial.println("Selected blue color");
        Color_Light(255,0,0);
        delay(750);
        break;
      case 2:
        Serial.println("Selected green color!");
        Color_Light(0,0,255);
        delay(750);
        break;
      case 3:
        Serial.println("Selected red color!");
        Color_Light(0,255,0);
        delay(750);
        break;
    }
    delay(20);
}

if(plusLastState == LOW && plusState == HIGH){
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
    delay(20);
}

if(minusLastState == LOW && minusState == HIGH){
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
    delay(20);
}

Color_Light(Color.blue,Color.red,Color.green);

plusLastState = plusState;
minusLastState = minusState;
colorSelectorLastState = colorSelectorState;
delay(15);
}