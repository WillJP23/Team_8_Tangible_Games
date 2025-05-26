# Team 8: Development Portfolio
## Class Lessions
- Contains photo and video documentation of skills learnt during this period include: LED blinking & fading, resistors & photo-resistors, wireless comunication, servos, LED strips & accelerometers.
## Circuit Development
- This contains the plan for the circuitry made on tinkercad first to test it; originally ithe circuit was going to use RGB LEDs, but was decided against due to them needing 3 Pins on the arduino boards.
- There was some debate between using 2 PIN RGB LEDs, but in the end the project used 1 green & 1 red LED instead.
- Initially the circuit was going to have 9 buttons to go with the LEDS, but this also ran into the issue with Pin slots on the arduino.
- For awhile the LED selector was done through coding, but 2 large buttons were used in place of this for the input so the game could be played without the use of a computer.
## Code Development
- Initially the code was built by copying the tinkercad code from the designs.
- After this, the variables were defined such as the posistions of the LEDs, the current player and the states of the LEDs(on/off).
- I started off the coding by adding a message to display the current player, then I added an input for the serial where i could type the posistion in place of a button
  (this input box was added as an inital replacement for the 9 buttons, after realising I didn't have enought slots to work with).
- I then added the win conditions and a game tracker to display which colour player won & how many games they won.
- After many bug fixes and problem solving, the code and circuitry was functional, but it was reconmended that we try adding a button to make the game more tangible.
- After looking into coding buttons, I found a way of adding a button using only 1 Pin, the 5V & the ground, so I was able to fit 2 buttons onto the board with the remaining pins.
- Then I added the basic code, suggested by arduino, I had to adapt this to my current code, but it was quite simple and the button was working and I could count up and down using the 2 buttons- Red being minus & green being plus.
- The issue I then had was combining the working code for the 18 LEDs & the 2 buttons - this took some time as I had to adapt quite a few things in the code to match and then systematically bug fix to get the code working.
- Eventually I managed to get this code to work & removed the computer serial input code as this was no longer needed or functional.
- The final piece of code I added was to make all the lights go green or red on the relevant player winning.
