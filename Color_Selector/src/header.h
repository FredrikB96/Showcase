#ifndef HEADER_H_
#define HEADER_H_

#include <Arduino.h>
#include <stdint.h>

#define PLUS_BUTTON   37 // Connected to button representing ADD value/color
#define MINUS_BUTTON    36 // Connected to button representing SUBTRACT value/color
#define COLOR_SELECTOR_BUTTON   35 // Connected to button representing Color Selection

#define BLUE_PIN  9 // Connected to blue pin of RGB Light
#define RED_PIN   7 // Connected to red pin of RGB Ligth
#define GREEN_PIN 8 // Connected to green pin of RGB light

#define COLOR_DELAY 750 // How long the selcted color are shown. Messured in MS

#define MAX_NUMBER_OF_COLORS 3
#define START_COLOR 1

// Struct holding the values of each color and currently selected color
typedef struct 
{
  uint16_t colorSelector;
  uint16_t blue;
  uint16_t red;
  uint16_t green;
}RGB_COLOR;

// Struct holding the different states of each button
typedef struct {
  uint16_t plus;
  uint16_t minus;
  uint16_t ColorSelection;
}States;

/*
*   Function declarations
*/
void start(); // Function to test each color pin of RGB Ligth
int16_t button_Reader(uint16_t button); // Function to debounce a button
void RGB_Lighter(uint32_t blueColor, uint32_t redColor, uint32_t greenColor); // Function to light the RGB led with correct color values

#endif /* HEADER_H_ */