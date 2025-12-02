/*
Normalmente quando um botão é pressionado ele fica continuamente a "mandar" o seu estado ao programa.

Se quizermos ter uma acção única quando pressionamos o botão é necessário implementar uma lógica
de mudança de estado, esta lógica tem o nome técnico: debounce.
*/

// botoes pins
int bt1_pin = 12;

//variavel para conter o estado do botao 
int bt1_read;

// variavel que contem o ultimo estado em que o botao se encontra, 
// serve como termo de comparação na lógica de "debounce"
int bt1_read_last;

void setup() {
  Serial.begin(9600);
  pinMode(bt1_pin, INPUT_PULLUP);
}

void loop() {
  // leitura do estado do botao
  bt1_read = digitalRead(bt1_pin);  

  // comparar o estado de leitura momentanea com o último estado
  // se for verdade quer dizer que o botao foi pressionado
  // caso contrario quer dizer que o botao foi solto
  if (bt1_read == 1 && bt1_read_last == 0)
  {
    Serial.println("button 1 is released");
  }
  if (bt1_read == 0 && bt1_read_last == 1)
  {
    Serial.println("button 1 is pressed");
  }
  
  // actualizar o ultimo estado
  bt1_read_last = bt1_read;
}
