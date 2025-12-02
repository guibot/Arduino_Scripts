/*
  maquina de estados com buzzer a tocar differentes arpeggios com tempos diferentes

  ver exemplos anteriores para uma explicação mais obvia da máquina de estados

*/
//////////////////////////////////// MIDI
//#include <MIDI.h>
//MIDI_CREATE_DEFAULT_INSTANCE();

int random_note1, random_note2;


//////////////////////////////////// CHRONO
// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h>
// Instanciate a Chrono object.
Chrono ledChrono;
Chrono arpeggioChrono;

//////////////////////////////////// PITCHES
// incluir ficheiro pitches - contem as frequencias para cada nota
#include "pitches_midi.h"

// array com notas do arpeggios
int arpeggio1[] = {NOTE_C3, NOTE_E3, NOTE_G3};
int arpeggio2[] = {NOTE_C3, NOTE_F3, NOTE_A3};
int arpeggio3[] = {NOTE_B2, NOTE_E3, NOTE_G3};

//////////////////////////////////// IO

int buzzer_pin = 9;
int thisNote;
int pot_val;
//
// botoes pins
int bt1_pin = 12;
int bt2_pin = 11;

//variavel para conter o estado do botao
int bt1_read, bt2_read;
int bt1_read_last, bt2_read_last;

// variavel de estados
int state = 1;

// variavel que armazena o ultimo estado do state
// para servir de comparação
int state_read_last;

// variavel do total de estados
int state_max = 3;

// led
int led_pin = 10;

//Create a variable to hold the led's state
int ledState = HIGH;

//////////////////////////////////// LED_RGB

// biblioteca Ramp serve para suavizar uma transição de um valor para o outro
#include <Ramp.h>  

// instancias das bibliotecas
Chrono red_chrono, green_chrono, blue_chrono;
ramp red_ramp, green_ramp, blue_ramp; 

int red_random, green_random, blue_random;

// valores do led rgb
int red_val, green_val, blue_val;

// pins do led rgb
int red_pin = 3;
int green_pin = 6;
int blue_pin = 5;

//////////////////////////////////// SETUP

void setup() {
  Serial.begin(9600);
  pinMode(bt1_pin, INPUT_PULLUP);
  pinMode(bt2_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
}

//////////////////////////////////// LOOP

void loop() {
  // le botoes e faz debounce
  button_debounce();

  // chama led_blink() e passa o parametro "state"
  led_blink(state);

  // chama buzzer_arpeggio() e passa o parametro "state"
  buzzer_arpeggio(state);

  if (state != state_read_last)
  {
    // Serial.print("state = ");
    // Serial.println(state);
  }
  state_read_last = state;

  // led rgb
  led_rgb();
}

//////////////////////////////////// LED RGB

void led_rgb() 
{
  if (red_chrono.hasPassed(analogRead(0)*2))
  {
    red_ramp.go(random(255), 1000);
    red_random = random(1000);
    red_chrono.restart();
  }

  if (green_chrono.hasPassed(analogRead(0)*2)) 
  {
    green_ramp.go(random(255), 1000);
    green_random = random(1000);
    green_chrono.restart();
  }

  if (blue_chrono.hasPassed(analogRead(0)*2)) 
  {
    blue_ramp.go(random(255), 1000);
    blue_random = random(1000);
    blue_chrono.restart();
  }

  analogWrite(red_pin, red_ramp.update());
  analogWrite(green_pin, green_ramp.update());
  analogWrite(blue_pin, blue_ramp.update());
 
}

//////////////////////////////////// ARPEGGIO

void buzzer_arpeggio(int _state)
{
  // le o potenciometro, mapeia o valor do pot e atribui este valor ao tempo de espera entre cada nota
  pot_val = analogRead(A0);

  // recebe o parametro state e passa para a variavel interna _state
  // ve em que estado é que se encontra
  // consoate o estado vai buscar as notas à array correspondente


  // sempre que o chrono é inicializado passa para a nota seguinte
  // o valor de espera muda consoante a leitura do pot
  if (arpeggioChrono.hasPassed(pot_val) ) {
    
      if (_state == 1)
      {
      noteOn(arpeggio1[thisNote], 127, pot_val);
      tone(buzzer_pin, arpeggio1[thisNote], 200);
      }
      if (_state == 2)
      {
      noteOn(arpeggio2[thisNote], 127, pot_val);
      tone(buzzer_pin, arpeggio2[thisNote], 200);
      }
      if (_state == 3)
      {
      noteOn(arpeggio3[thisNote], 127, pot_val);
      tone(buzzer_pin, arpeggio3[thisNote], 200);
      }
    
    if (thisNote < 2)
    {
      thisNote++;
    }
    else
    {
      thisNote = 0;
    }

    arpeggioChrono.restart();
  }
}

//////////////////////////////////// LED

void led_blink(int _state)
{
  int state_delay;

  if (_state == 1)
    state_delay = 100;
  if (_state == 2)
    state_delay = 500;
  if (_state == 3)
    state_delay = 1000;

  if (ledChrono.hasPassed(state_delay) ) { // returns true if it passed 1000 ms since it was started
    ledChrono.restart();  // restart the crono so that it triggers again later

    // toggle the stored state
    if (ledState == HIGH)  ledState = LOW;
    else ledState = HIGH;

    // write the state to the pin
    digitalWrite(led_pin, ledState);
  }
}



//////////////////////////////////// BUTTON DEBOUNCE

void button_debounce() {
  // leitura do estado do botao
  bt1_read = digitalRead(bt1_pin);
  bt2_read = digitalRead(bt2_pin);

  // debounce bt1
  if (bt1_read == 1 && bt1_read_last == 0)
  {
    //Serial.println("  button 1 is released");
  }
  else if (bt1_read == 0 && bt1_read_last == 1)
  {
    //Serial.println("  button 1 is pressed");
    if (state > 1)
    {
      state--;
    }
    else
    {
      if (state == 1)
        state = 3;
    }
  }


  // debounce bt2
  if (bt2_read == 1 && bt2_read_last == 0)
  {
    //Serial.println("  button 2 is released");
  }
  else if (bt2_read == 0 && bt2_read_last == 1)
  {
    //Serial.println("  button 2 is pressed");
    if (state < state_max)
    {
      state++;
    }
    else
    {
      if (state == state_max)
        state = 1;
    }
  }

  // actualizar o ultimo estado
  bt1_read_last = bt1_read;
  bt2_read_last = bt2_read;

  //Serial.println(state);
}


//////////////////////////////////// NOTEON NOTEOFF

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
