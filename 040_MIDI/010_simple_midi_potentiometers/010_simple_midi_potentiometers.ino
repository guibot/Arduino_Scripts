// total number of devices
#define POTS_TOTAL 4

// variables
int pot_pins[POTS_TOTAL] = {A0, A1, A2, A3};
int pot_raw_value[POTS_TOTAL];
int pot_mapped[POTS_TOTAL];
int pot_smooth[POTS_TOTAL];
float pot_filter = 0.1;
int pot_previous[POTS_TOTAL];

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // read devices
  for(int i=0; i<POTS_TOTAL; i++)
  {
    pot_raw_value[i] = analogRead(pot_pins[i]); 
    pot_mapped[i] = map(pot_raw_value[i], 0, 1023, 0, 137);

    // filter noise issues with analog devices
    pot_smooth[i] = pot_smooth[i] * (1.0 - pot_filter) + pot_mapped[i] * pot_filter;

    // if values changed send MIDI message
    if(pot_smooth[i] != pot_previous[i])
    {
      //Serial.print (pot_smooth[i]); 
      //Serial.println();

      // send MIDI CC
      usbMIDI.sendControlChange(i+1, pot_smooth[i], 1);

      // update variable to be able to compare for value changes
      pot_previous[i] = pot_smooth[i];
    }

    /*
    Serial.print(pot_raw_value[i]);
    Serial.print("   ");
    Serial.print(pot_mapped[i]);
    Serial.print("   ");
    Serial.print(pot_smooth[i]);
    Serial.print(" :: ");
    /**/
  }
  while (usbMIDI.read());
  //Serial.println();
}
