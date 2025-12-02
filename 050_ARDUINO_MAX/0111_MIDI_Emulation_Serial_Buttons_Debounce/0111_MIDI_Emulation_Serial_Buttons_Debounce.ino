/*
 * This program is sending MIDI notes with a press of a button
 * Boards like the Leonardo can output Midi USB out of the box
 * But with boards like the UNO or Diecimila there's no way to send MIDI through USB
 * This program sends Serial messages every time a button is pressed and released
 * The noteon() function is sending also a sensor value, it is supposed to be assigned to the note duration
 */


//////////////////////////////////// BUTTON 1 DEBOUNCE

// constants won't change. They're used here to set pin numbers:
const int button1_pin = 12;    // the number of the pushbutton pin
const int led1_pin = 13;      // the number of the LED pin
const int led2_pin = 8; 

// Variables will change:
int led1_state = HIGH;         // the current state of the output pin
int led2_state = HIGH;

int button1_state_LOW;             // the current reading from the input pin
int button1_state_HIGH;

int lastButton1_state_LOW = LOW;   // the previous reading from the input pin
int lastButton1_state_HIGH = HIGH;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounce1_time = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int counter;

int analog_value;

//////////////////////////////////// MIDI
//#include <MIDI.h>
//MIDI_CREATE_DEFAULT_INSTANCE();

int random_note1, random_note2;

//////////////////////////////////// SETUP

void setup() {
  Serial.begin(9600);
  pinMode(button1_pin, INPUT_PULLUP);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  // set initial LED state
  digitalWrite(led1_pin, led1_state);
}

//////////////////////////////////// LOOP

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(button1_pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButton1_state_LOW) {
    // reset the debouncing timer
    lastDebounce1_time = millis();
  }

  if ((millis() - lastDebounce1_time) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != button1_state_LOW) {
      button1_state_LOW = reading;
      
      // only toggle the LED if the new button state is HIGH
      if (button1_state_LOW == LOW) {
        //Serial.print("bt pressed counter: ");
        //Serial.println(counter++);

        // MIDI NOTE ON
        random_note1 = random(127);
        analog_value = analogRead(0);
        noteOn(random_note1, 127, analog_value);
    
        led1_state = !led1_state;
      }
    }

    // if the button state has changed:
    if (reading != button1_state_HIGH) {
      button1_state_HIGH = reading;

      // only toggle the LED if the new button state is HIGH
      if (button1_state_HIGH == HIGH) {
        //Serial.println("bt released");

        // MIDI NOTE OFF
        noteOff(random_note1, 0, analog_value);     // Stop the note

        led2_state = !led2_state;
      }
    }
  }

  // set the LED:
  digitalWrite(led1_pin, led1_state);
  digitalWrite(led2_pin, led2_state);

  // save the reading. Next time through the loop, it'll be the lastButton1_state_LOW:
  lastButton1_state_LOW = reading;
  lastButton1_state_HIGH = reading;
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
