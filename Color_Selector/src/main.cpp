#include <Arduino.h>

#define PLUS_BUTTON   37
#define MINUS_BUTTON    36
#define COLOR_SELECTOR_BUTTON   35

#define BLUE_PIN  7 
#define RED_PIN   8 
#define GREEN_PIN 9 

int blue = 0;
int red = 0;
int green = 0;

int plusState = HIGH;
int minusState = HIGH;
int colorSelectorState = HIGH;

int plusLastState = LOW;
int minusLastState = LOW;
int colorSelectorLastState = LOW;

int colorSelector = 0;

int startUp = 0;

void setup(){
  Serial.begin(9600);

  pinMode(PLUS_BUTTON,INPUT_PULLUP);
  pinMode(MINUS_BUTTON,INPUT_PULLUP);
  pinMode(COLOR_SELECTOR_BUTTON,INPUT_PULLUP);

  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  delay(1000);
}

void start(){
  startUp++;

  delay(2000);
  digitalWrite(BLUE_PIN,255);
  digitalWrite(RED_PIN,0);
  digitalWrite(GREEN_PIN,0);

  delay(2000);
  digitalWrite(BLUE_PIN,0);
  digitalWrite(RED_PIN,255);
  digitalWrite(GREEN_PIN,0);

  delay(2000);
  digitalWrite(BLUE_PIN,0);
  digitalWrite(RED_PIN,0);
  digitalWrite(GREEN_PIN,255);

  delay(2000);
}

void RGB_COLOR(int BlueColor, int RedColor, int GreenColor){
analogWrite(BLUE_PIN,BlueColor);
analogWrite(RED_PIN,RedColor);
analogWrite(GREEN_PIN,GreenColor);
}

void loop(){
  if(startUp<1){
    start();
  }

plusState = digitalRead(PLUS_BUTTON);
minusState = digitalRead(MINUS_BUTTON);
colorSelectorState = digitalRead(COLOR_SELECTOR_BUTTON);

if(colorSelectorLastState == LOW && colorSelectorState == HIGH){
  colorSelector++;

  if(colorSelector>3){
    colorSelector = 1;
  }

     switch (colorSelector)
    {
      case 1:
        Serial.println("Selected red color"); 
        RGB_COLOR(255,0,0);
        delay(1000);
        break;
      case 2:
        Serial.println("Selected blue color!");
        RGB_COLOR(0,0,255);
        delay(1000);
        break;
      case 3:
        Serial.println("Selected green color!");
        RGB_COLOR(0,255,0);
        delay(1000);
        break;
    }
    delay(20);
}

if(plusLastState == LOW && plusState == HIGH){
    switch (colorSelector)
    {
      case 1:
        blue +=51;
        Serial.print("RED: "); Serial.println(blue);
        break;
      case 2:
        green +=51;
        Serial.print("BLUE: "); Serial.println(green);
        break;
      case 3:
        red +=51;
        Serial.print("GREEN: "); Serial.println(red);
        break;
    }

    if(red>255){
      red = 0;
      Serial.print("NEW GREEN: "); Serial.println(red);
    }
    if(blue>255){
      blue = 0;
      Serial.print("NEW RED: "); Serial.println(blue);
    }
    if(green>255){
      green = 0;
      Serial.print("NEW BLUE: "); Serial.println(green);
    }
    delay(20);
}

if(minusLastState == LOW && minusState == HIGH){
      switch (colorSelector)
    {
      case 1:
        blue -=51;
        Serial.print("RED: "); Serial.println(blue);
        break;
      case 2:
        green -=51;
        Serial.print("BLUE: "); Serial.println(green);
        break;
      case 3:
        red -=51;
        Serial.print("GREEN: "); Serial.println(red);
        break;
    }

    if(red<0){
      red = 255;
      Serial.print("NEW GREEN: "); Serial.println(red);
    }
    if(blue<0){
      blue = 255;
      Serial.print("NEW RED: "); Serial.println(blue);
    }
    if(green<0){
      green = 255;
      Serial.print("NEW BLUE: "); Serial.println(green);
    }
    delay(20);
}

RGB_COLOR(blue,red,green);

plusLastState = plusState;
minusLastState = minusState;
colorSelectorLastState = colorSelectorState;
delay(15);
}