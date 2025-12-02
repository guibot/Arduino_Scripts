#include "Debouncer.h"
#define TOTAL_BUTTONS 4
Debouncer buttons_val[TOTAL_BUTTONS];
int buttons_pins[] = {1, 2, 3, 4};
int buttons_val_previous[TOTAL_BUTTONS];
int midi_pitch[] = {48, 51, 55, 60};

int pot1, pot2, pot3, pot4;


void setup() {
  Serial.begin(115200);
  for (int i=0; i<TOTAL_BUTTONS; i++)
    pinMode(buttons_pins[i], INPUT);
}

void loop() {
  pot1 = map (analogRead(14), 0, 1023, 0, 127);
  pot2 = map (analogRead(15), 0, 1023, 0, 127);
  pot3 = map (analogRead(16), 0, 1023, 0, 127);
  pot4 = map (analogRead(17), 0, 1023, 0, 127);
  
  usbMIDI.sendControlChange(1, pot1, 1);
  usbMIDI.sendControlChange(2, pot2, 1);
  usbMIDI.sendControlChange(3, pot3, 1);
  usbMIDI.sendControlChange(4, pot4, 1);

  for (int i=0; i<TOTAL_BUTTONS; i++)
  {
    buttons_val[i]._reading = digitalRead(buttons_pins[i]);
    buttons_val[i].run();

    if (buttons_val_previous[i] != buttons_val[i]._state && buttons_val[i]._reading == 1)
    {
      buttons_val_previous[i] = buttons_val[i]._state;
      
      if (buttons_val[i]._state == 1) {
        usbMIDI.sendNoteOn(midi_pitch[i], 127, 1);
        return;
      }
      else
      {
        usbMIDI.sendNoteOn(midi_pitch[i], 0, 1);
        return;
      }
    }

    
    Serial.print(buttons_val[i]._buttonState);
    Serial.print(" ");
    Serial.print(buttons_val[i]._state);
    Serial.print(" ");
  }
  Serial.println();

  
}
