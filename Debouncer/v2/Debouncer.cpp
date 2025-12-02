#include "Debouncer.h"

Debouncer::Debouncer()
{
  _lastButtonState = LOW;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
  _state = LOW;  
  
}


Debouncer::~Debouncer()
{
  
}

void Debouncer::insert_manual_state(uint8_t _virtualstate)//, int _virtualButtonState)
{
  _state = _virtualstate;
  //_buttonState = _virtualButtonState;
}

void Debouncer::run()
{
  if (_reading != _lastButtonState) {
    // reset the debouncing timer
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _debounceDelay) { 
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (_reading != _buttonState) {
     _buttonState = _reading;

      // only toggle the LED if the new button state is HIGH
      if (_buttonState == HIGH) {
        _state = !_state;
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  _lastButtonState = _reading;
}

void Debouncer::reset()
{
  _lastButtonState = LOW;
  _state = LOW;  
}
