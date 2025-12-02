/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Debouncer_h
#define Debouncer_h

#include "Arduino.h"

class Debouncer
{
  public:
    Debouncer(int pin);
	int state;      // the current state1 of the output pin
  	int reading;           // the current reading1 from the input pin
	int previous;    // the previous1 reading1 from the input pin
	long time;         // the last time1 the output pin was toggled
	long debounce;   // the  time1, increase if the output flickers  private:
	int updater();
  private:
    int _pin;
};

#endif



