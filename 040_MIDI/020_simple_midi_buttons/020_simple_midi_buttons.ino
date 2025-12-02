#include <JC_Button.h>

#define BUTTONS_TOTAL 4

int leds_pins[BUTTONS_TOTAL] = {9, 10, 11, 12};

ToggleButton buttons[BUTTONS_TOTAL] = {5, 6, 7, 8};
int button_cc_msg[BUTTONS_TOTAL];


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < BUTTONS_TOTAL; i++)
  {
    buttons[i].begin();
    pinMode(leds_pins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < BUTTONS_TOTAL; i++)
  {
    buttons[i].read();
    
    
    if (buttons[i].changed())
    {
      if (buttons[i].toggleState() == 1)
        button_cc_msg[i] = 127;
      else
        button_cc_msg[i] = 0;

      usbMIDI.sendControlChange(i+1, button_cc_msg[i], 1);

      digitalWrite(leds_pins[i], buttons[i].toggleState());
      
      Serial.print(i);
      Serial.print(" ");
      Serial.print(buttons[i].toggleState());
      Serial.println();
    }
  }
  while (usbMIDI.read());
}
