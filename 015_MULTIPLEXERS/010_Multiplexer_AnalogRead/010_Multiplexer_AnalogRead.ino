// Incluir a Biblioteca MUX74HC4067
#include "MUX74HC4067.h"

// Instaciar a Biblioteca com o nome mux_pots
// Enable pin - GND
// S0, S1, S2, S3 - 9, 10, 11, 12
MUX74HC4067 mux_pots(3, 9, 10, 11, 12);

// array com 16 indices
int pot_value[16];

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
		pot_value[i] = mux_pots.read();
	
		Serial.print(pot_value[i]);
		Serial.print("\t");
	}
	Serial.println();
	delay(1);
}
