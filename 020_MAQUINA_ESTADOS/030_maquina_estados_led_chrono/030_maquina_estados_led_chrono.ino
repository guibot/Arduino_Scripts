/*
maquina de estados com led a piscar a tempos diferentes
no exemplo anterior estava a ser utilizado o comando delay()

neste exemplo estamos a usar a biblioteca Chronos

Esta biblioteca é uma implementação de um cronómetro, agora em vez de delay
vamos passar a utilizar um contador de tempo que não impeça o programa de continuar
a fazer outras tarefas em simultaneo
*/

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

// Instanciate a Chrono object.
Chrono ledChrono; 


// botoes pins
int bt1_pin = 12;
int bt2_pin = 13;

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

  // chama led_blink e passa o parametro "state"
  led_blink(state);

  if (state != state_read_last)
  {
    Serial.print("state = ");
    Serial.println(state);
  }

  state_read_last = state;
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
    if (ledState==HIGH)  ledState=LOW;
    else ledState=HIGH;
    
    // write the state to the pin
    digitalWrite(led_pin,ledState);
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
