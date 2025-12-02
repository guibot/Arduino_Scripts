// Incluir a Biblioteca MUX74HC4067
#include "MUX74HC4067.h"

// Instaciar a Biblioteca com o nome mux_pots
// Enable pin - GND
// S0, S1, S2, S3 - 9, 10, 11, 12
MUX74HC4067 mux_pots(3, 9, 10, 11, 12);

// total n. de dispositivos
#define POTS_TOTAL 16
// array com 16 indices
int pot_value[POTS_TOTAL];
int pot_raw_value[POTS_TOTAL];
int pot_mapped[POTS_TOTAL];
int pot_smooth[POTS_TOTAL];
float pot_filter = 0.1;
int pot_previous[POTS_TOTAL];

void setup() {
  Serial.begin(9600);
  // declarar mux_pots como Input, Analógico, Signal Pin - A0
  mux_pots.signalPin(A0, INPUT, ANALOG);
}

void loop() {
  read_pots();
}

void read_pots() {
  for (byte i = 0; i < 16; ++i)
  {
    // leitura do canal 'i' atribuida ao índice 'i'
    mux_pots.setChannel(i);

    pot_raw_value[i] = mux_pots.read();
    pot_mapped[i] = map(pot_raw_value[i], 0, 1023, 0, 137);

    // filter noise issues with analog devices
    pot_smooth[i] = pot_smooth[i] * (1.0 - pot_filter) + pot_mapped[i] * pot_filter;

    // if values changed send MIDI message
    if (pot_smooth[i] != pot_previous[i])
    {
      //Serial.print (pot_smooth[i]);
      //Serial.println();

      // send MIDI CC
      usbMIDI.sendControlChange(i + 1, pot_smooth[i], 1);

      // update variable to be able to compare for value changes
      pot_previous[i] = pot_smooth[i];
    }

    /**/
      //Serial.print(pot_raw_value[i]);
      //Serial.print("   ");
      Serial.print(pot_mapped[i]);
      Serial.print("   ");
      Serial.print(pot_smooth[i]);
      Serial.print(" :: ");
      /**/
  }
  while (usbMIDI.read());
  Serial.println();
}
