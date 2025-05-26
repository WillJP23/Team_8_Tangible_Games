# Code Development
Folder containing photos & videos of code.
## Code Explaination
- Image 1: Arduino Digital Pin & button settup, buttons are set to 'pullup' so as to not require a resistor, serial number is added so that the box can be used with code.
- Images 2 & 3: Variables defined, 'pos' refers to posisiton of the LED, g1/r2 etc. refers to green & red LED- true/false for if that position is selected- greenred refers to the current player, 'win' refers to if a win state is achieved, 'message' is used to block or display a messgae on the serial box to prevent spamming from the loop, buttonstate & count are related to which button is pushed & what number it is currently on.
- Images 4 & 6: code used to track what colour lights are on & what position.
- Images 7 - 10: winning script for if the previous code is activated, turns all the coloured lights on for the winning player, & resets their values afterwards.
- Image 11: code to display the current player in the serial box
- Image 12: commented code for the manual posistion input instead of a button push
- Images 13 - 21: Green Button Code; counts up and will flash light on position depending on if lights are already on or not.
- Images 22 - 26: Red Button Code; when red button is pushed, depending on the current player a light will be lit on that position
- Images 27: Resets the button code after going through it once and both buttons are not pressed
- Images G1-G9: Older versions of the Red Button code.
## Useful Code Folder
- Code given in class that was used initally to start off some of the code
