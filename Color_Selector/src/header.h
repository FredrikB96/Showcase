#define PLUS_BUTTON   37 // Connected to button representing ADD value/color
#define MINUS_BUTTON    36 // Connected to button representing SUBTRACT value/color
#define COLOR_SELECTOR_BUTTON   35 // Connected to button representing Color Selection

#define BLUE_PIN  9 // Connected to blue pin of RGB Light
#define RED_PIN   7 // Connected to red pin of RGB Ligth
#define GREEN_PIN 8 // Connected to green pin of RGB light

#define COLOR_DELAY 750 // How long the selcted color are shown. Messured in MS

// Struct holding the values of each color and currently selected color
typedef struct 
{
  int colorSelector;
  int blue;
  int red;
  int green;
}RGB_COLOR;

/*
*   Function declarations
*/
void start(); // Function to test each color pin of RGB Ligth
void Color_Light(int blueColor, int redColor, int greenColor); // Function to Light each pin with correct amount of color/value
int Debounce_Button(int state, int button); // Function to debounce a button