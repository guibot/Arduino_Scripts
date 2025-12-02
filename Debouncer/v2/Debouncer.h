/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  *****************************

      modified by Guilherme Martins @ 15 August 2018
      to be used as a generic debouncer state machine
  
  *****************************
  
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/


#ifndef Debouncer_h
#define Debouncer_h

#include "Arduino.h"


class Debouncer
{
  public:
    Debouncer();
    ~Debouncer();

  uint8_t _buttonState;
  uint8_t _lastButtonState;
  uint8_t _state;

  // the following variables are unsigned longs because the time, measured in
  // milliseconds, will quickly become a bigger number than can be stored in an int.
  unsigned long _lastDebounceTime;  // the last time the output pin was toggled
  unsigned long _debounceDelay;

  uint8_t _reading;

  void run();
  void reset();
  void insert_manual_state(uint8_t _virtualstate);//, int _virtualButtonState);


};

#endif
