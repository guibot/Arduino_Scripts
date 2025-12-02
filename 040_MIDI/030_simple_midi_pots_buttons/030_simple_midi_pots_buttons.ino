// total number of devices
#define DEVICES_TOTAL 4

/* * * * * * * * * * * * * * * * * * * * * * * *
  /
  //  BUTTONS VARIABLES
  /
  /* * * * * * * * * * * * * * * * * * * * * * * */

#include <JC_Button.h>
int leds_pins[DEVICES_TOTAL] = {9, 10, 11, 12};
ToggleButton buttons[DEVICES_TOTAL] = {5, 6, 7, 8};
int button_cc_msg[DEVICES_TOTAL];

/* * * * * * * * * * * * * * * * * * * * * * * *
  /
  //  POTENTIOMETERS VARIABLES
  /
  /* * * * * * * * * * * * * * * * * * * * * * * */

// potentiometers variables
int pot_pins[DEVICES_TOTAL] = {A0, A1, A2, A3};
int pot_raw_value[DEVICES_TOTAL];
int pot_mapped[DEVICES_TOTAL];
int pot_smooth[DEVICES_TOTAL];
float pot_filter = 0.1;
int pot_previous[DEVICES_TOTAL];

/* * * * * * * * * * * * * * * * * * * * * * * *
  /
  //  SETUP
  /
  /* * * * * * * * * * * * * * * * * * * * * * * */
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < DEVICES_TOTAL; i++)
  {
    buttons[i].begin();
    pinMode(leds_pins[i], OUTPUT);
  }
}

/* * * * * * * * * * * * * * * * * * * * * * * *
  /
  //  LOOP
  /
  /* * * * * * * * * * * * * * * * * * * * * * * */
void loop()
{
  read_potentiometers();
  read_buttons();
  while (usbMIDI.read());
}
/* * * * * * * * * * * * * * * * * * * * * * * *
  /
  //  BUTTONS READ
  /
  /* * * * * * * * * * * * * * * * * * * * * * * */
void read_buttons()
{
  for (int i = 0; i < DEVICES_TOTAL; i++)
  {
    buttons[i].read();
    if (buttons[i].changed())
    {
      if (buttons[i].toggleState() == 1)
        button_cc_msg[i] = 127;
      else
        button_cc_msg[i] = 0;
      usbMIDI.sendControlChange(i + 5, button_cc_msg[i], 1);
      digitalWrite(leds_pins[i], buttons[i].toggleState());
    }
  }
}
/* * * * * * * * * * * * * * * * * * * * * * * *
  /
  //  POTENTIOMETERS READ
  /
  /* * * * * * * * * * * * * * * * * * * * * * * */
void read_potentiometers()
{
  for (int i = 0; i < DEVICES_TOTAL; i++)
  {
    pot_raw_value[i] = analogRead(pot_pins[i]);
    pot_mapped[i] = map(pot_raw_value[i], 0, 1023, 0, 137);

    // filter noise issues with analog devices
    pot_smooth[i] = pot_smooth[i] * (1.0 - pot_filter) + pot_mapped[i] * pot_filter;

    // if values changed send MIDI message
    if (pot_smooth[i] != pot_previous[i])
    {
      // send MIDI CC
      usbMIDI.sendControlChange(i + 1, pot_smooth[i], 1);

      // update variable to be able to compare for value changes
      pot_previous[i] = pot_smooth[i];
    }
  }
}
