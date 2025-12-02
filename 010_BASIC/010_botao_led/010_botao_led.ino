/* int - inteiro
   float - decimal
   bool - boleano - true / false  */

int led_azul_pin = 13; 
int led_verde_pin = 8; 
int botao_pin = 2;

void setup() {
  pinMode(led_azul_pin, OUTPUT); // LED
  pinMode(led_verde_pin, OUTPUT); // LED
  pinMode(botao_pin, INPUT_PULLUP);  //BOTÃO
}

void loop() {
  // condição / comparação
  if (digitalRead(botao_pin) != HIGH)
  {
    // se for verdadeiro executa
    digitalWrite(led_azul_pin, HIGH);
    digitalWrite(led_verde_pin, LOW);
  }
  else
  {
    // se não for verdadeiro executa aqui
    digitalWrite(led_azul_pin, LOW);
    digitalWrite(led_verde_pin, HIGH);
  }
}
