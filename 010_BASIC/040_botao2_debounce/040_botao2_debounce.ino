// botoes pins
int bt1_pin = 12;
int bt2_pin = 7;

//variavel para conter o estado do botao 
int bt1_read, bt2_read;

// variavel que contem o ultimo estado em que o botao se encontra, 
// serve como termo de comparação na lógica de "debounce"
int bt1_read_last, bt2_read_last;

void setup() {
  Serial.begin(9600);
  pinMode(bt1_pin, INPUT_PULLUP);
  pinMode(bt2_pin, INPUT_PULLUP);
}

void loop() {
  // leitura do estado do botao
  bt1_read = digitalRead(bt1_pin);  
  bt2_read = digitalRead(bt2_pin);  

  // debounce bt1
  if (bt1_read == 1 && bt1_read_last == 0)
  {
    Serial.println("button 1 is released");
  }
  else if (bt1_read == 0 && bt1_read_last == 1)
  {
    Serial.println("button 1 is pressed");
  }


  // debounce bt2
  if (bt2_read == 1 && bt2_read_last == 0)
  {
    Serial.println("button 2 is released");
  }
  else if (bt2_read == 0 && bt2_read_last == 1)
  {
    Serial.println("button 2 is pressed");
  }
  
  // actualizar o ultimo estado
  bt1_read_last = bt1_read;
  bt2_read_last = bt2_read;
}
