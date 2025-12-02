/*
  DEBOUNCER Library created from the original Debouncer code
*/

#include "Arduino.h"
#include "Debouncer.h"

Debouncer::Debouncer(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  state = HIGH;
  previous = LOW; 
  time = 0;
  debounce = 200;
}

int Debouncer::updater() {
   reading = digitalRead(_pin);
  // if we just pressed the button (i.e. the input went from LOW to HIGH),
  // and we've waited long enough since the last press to ignore any noise...  
  
  
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    // ... invert the output
    if (state == HIGH) {
      state = LOW;
    } else {
      state = HIGH;
    }
    // ... and remember when the last button press was
    time = millis();    
  }
  previous = reading;
  return state;
  
 
}