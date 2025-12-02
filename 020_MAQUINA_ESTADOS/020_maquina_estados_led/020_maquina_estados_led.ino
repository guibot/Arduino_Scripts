/*
maquina de estados com led a piscar a tempos diferentes
repara como funciona mal, e o estado nao muda quando se pressiona o botao

isto deve-se a que o comando delay(), sempre que utilizado paraliza o andamento do programa

neste caso específico precisamos que o led continue a piscar mas sem utilizar delay()

ve o proximo exemplo
*/

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
    
  
  digitalWrite(led_pin, HIGH);
  delay(state_delay);
  digitalWrite(led_pin, LOW);
  delay(state_delay);
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
