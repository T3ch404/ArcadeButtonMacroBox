#include <Keyboard.h>

// Pins are assigned from left to right, top to bottom.
int buttonPins[] = {9,8,7,4,16,14,15,A0,A1,A2};

// keyCodes range from F13 to F19. 
// What I assume to be F20 through F22 report as UNK131 through UNK133 when binding in discord
byte keyCodes[] = {0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9};

// LED sections are assigned from left to right, top to bottom
int LEDsection[] = {3,5,6,10};

void setup() {

  Keyboard.begin();
  
  // Button pin setup (Loop through each button pin and set as an input)
  for (int i = 0; i <= 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // LED pin setup (Loop through each LED pin and set as an output)
  for (int i = 0; i <= 3; i++) {
    pinMode(LEDsection[i], OUTPUT);
    digitalWrite(LEDsection[i], HIGH);
  }
}

void loop() {

  // Check button state (Loop through each button pin and check state)
  for (int i = 0; i <= 9; i++) {
    if (!digitalRead(buttonPins[i])) {
      Keyboard.write(keyCodes[i]);      // If the button is press send the key code that corresponds to that button
      delay(200);                       // delay for debounce
    }
  }
}
