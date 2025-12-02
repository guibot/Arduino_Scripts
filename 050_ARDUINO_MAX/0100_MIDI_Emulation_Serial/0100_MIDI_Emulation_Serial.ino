//#include <MIDI.h>
//MIDI_CREATE_DEFAULT_INSTANCE();

// adaptação do exemplo genérico de envio de mensagens MIDI - note on e note off
// utilizando a comunicação Serial
// este exeplo deverá ser utilizado em placas de Arduino
// que utilizem o ATMega 328 (Diecimila e UNO)



int serialvalue; // value for serial input
int started = 0; // flag for whether we've received serial yet

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //MIDI.begin(1);                      // Launch MIDI and listen to channel 4
}

void loop()
{
  int random_note = random(127);
  digitalWrite(LED_BUILTIN, HIGH);
  noteOn(random_note, 127, 1);    // Send a Note (pitch 42, velo 127 on channel 1)
  delay(1000);		            // Wait for a second
  noteOff(random_note, 0, 1);     // Stop the note
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}

void noteOn(int pitch, int velocity, int channel) {
  //MIDI.sendNoteOn(pitch, velocity, channel);
  Serial.print(pitch);
  Serial.print(" ");
  Serial.print(velocity);
  Serial.print(" ");
  Serial.print(channel);
  Serial.println();
}

void noteOff(int pitch, int velocity, int channel) {
  //MIDI.sendNoteOff(pitch, velocity, channel);
  Serial.print(pitch);
  Serial.print(" ");
  Serial.print(velocity);
  Serial.print(" ");
  Serial.print(channel);
  Serial.println();
}
