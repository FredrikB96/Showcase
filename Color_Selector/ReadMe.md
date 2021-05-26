|======== <b>COLOR SELECTOR</b> ========|

<b> Color Selector </b> are a program made
for the Teensy 3.5 board with arduino code.

The purpouse for the software are to enable
the user to select the color and the amount
of strength to that color.
User will be shown selected color before editing amount.

This are done by 3 buttons. 
One to select color.
One to add amount to that color.
One to subtract amount to that color.

!NB: The steps for adding and subtracting are made in 51 increments. This are done because 255 / 5 = 51. anything else under 10 are using decimals.

To setup this you will need:
- 1 Teensy 3.5 board
- 3 120Ohm resistors 
- 1 LED 5mm RGB diffus CC light
- 3 PCB 12x12x8,5mm Push Button
- 11+ Wires

Pins to wire the components to:
- Pin 9 of Teensy 3.5 to Blue pin of RGB LED
- Pin 7 of Teensy 3.5 to Red pin of RGB LED
- Pin 8 of Teensy 3.5 to Green pin of RGB LED

- Pin 35 of Teensy 3.5 to Color selection Button
- Pin 36 of Teensy 3.5 to Minus Button
- Pin 37 of Teensy 3.5 to Plus Button
- 
![RGB_Circuit](https://user-images.githubusercontent.com/17123698/119645024-dd3ca400-be1d-11eb-9d2e-c0f1d3605e47.png)
