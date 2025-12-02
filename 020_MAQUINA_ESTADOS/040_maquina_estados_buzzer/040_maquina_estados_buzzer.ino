/*
  maquina de estados com buzzer a tocar differentes arpeggios com tempos diferentes

  ver exemplos anteriores para uma explicação mais obvia da máquina de estados

*/

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h>
// Instanciate a Chrono object.
Chrono ledChrono;
Chrono arpeggioChrono;


// incluir ficheiro pitches - contem as frequencias para cada nota
#include "pitches.h"

// array com notas do arpeggios
int arpeggio1[] = {NOTE_C3, NOTE_E3, NOTE_G3};
int arpeggio2[] = {NOTE_C3, NOTE_F3, NOTE_A3};
int arpeggio3[] = {NOTE_B2, NOTE_E3, NOTE_G3};

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

void setup() {
  Serial.begin(9600);
  pinMode(bt1_pin, INPUT_PULLUP);
  pinMode(bt2_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // le botoes e faz debounce
  button_debounce();

  // chama led_blink() e passa o parametro "state"
  led_blink(state);

  // chama buzzer_arpeggio() e passa o parametro "state"
  buzzer_arpeggio(state);

  if (state != state_read_last)
  {
    Serial.print("state = ");
    Serial.println(state);
  }
  state_read_last = state;
}


void buzzer_arpeggio(int _state)
{
  // recebe o parametro state e passa para a variavel interna _state
  // ve em que estado é que se encontra
  // consoate o estado vai buscar as notas à array correspondente
  if (_state == 1)
    tone(buzzer_pin, arpeggio1[thisNote], 200);
  if (_state == 2)
    tone(buzzer_pin, arpeggio2[thisNote], 200);
  if (_state == 3)
    tone(buzzer_pin, arpeggio3[thisNote], 200);
    
  // le o potenciometro, mapeia o valor do pot e atribui este valor ao tempo de espera entre cada nota
  pot_val = map(analogRead(A0), 0, 1023, 10, 2000);

  // sempre que o chrono é inicializado passa para a nota seguinte
  // o valor de espera muda consoante a leitura do pot
  if (arpeggioChrono.hasPassed(pot_val) ) { 
    
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
      state--;
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
      state++;
  }

  // actualizar o ultimo estado
  bt1_read_last = bt1_read;
  bt2_read_last = bt2_read;
}
