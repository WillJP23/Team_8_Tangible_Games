/*
 * Debouncing a button.
 */

// Button must be stable for this many milliseconds before a state change is recognised.
#define DEBOUNCE_DELAY 2

#define BUTTON_PIN 8
#define LED_PIN 13

void setup()                    
{
   Serial.begin(9600);
   pinMode(BUTTON_PIN, INPUT_PULLUP);
   pinMode(LED_PIN, OUTPUT);
   digitalWrite(LED_PIN, LOW);
}

int debouncedButtonState = 0;
int lastButtonState = 0;
long lastBounceTime = millis();

int getDebouncedSwitch() {
  int buttonState = digitalRead(BUTTON_PIN);

  // If the switch state changed, due to noise or pressing, reset the debounce timer.
  if (buttonState != lastButtonState) {
    lastBounceTime = millis();
  }

  // If the same switch state has been there for longer than the debounce
  // delay, take it as the actual current state.
  if ((millis() - lastBounceTime) > DEBOUNCE_DELAY) {
      debouncedButtonState = buttonState;
  }

  lastButtonState = buttonState;
  return debouncedButtonState;
}

long time = millis();
int wasPressed = 1; // 0 = button pressed, 1 = button not pressed
uint8_t ledState = LOW;

void loop()                    
{
  int raw = digitalRead(BUTTON_PIN);
  int pressed = getDebouncedSwitch();
 
  if (millis() - time > 10) { // arbitrary delay to limit data to serial port
    Serial.print(raw);
    Serial.print("\t");
    Serial.println(pressed);

    time = millis();
  }

   // If the switch was newly pressed (active low), toggle the LED
  if (pressed == 0 && wasPressed == 1) {
    ledState = (ledState == LOW) ? HIGH : LOW;
  }

  wasPressed = pressed; // remember button state
  digitalWrite(LED_PIN, ledState);                          
}
