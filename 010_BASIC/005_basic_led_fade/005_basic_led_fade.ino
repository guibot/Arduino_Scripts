// porta do led
int led_pin = 9;

// valor de espera
int espera = 10;

void setup() {
  // inicialização da comunicação série
  Serial.begin(9600);

  // declaração do led como saída de voltagem
  pinMode(led_pin, OUTPUT);

}

void loop() {

  for (int i=0; i<255; i++)
  {
    analogWrite(led_pin, i);
    delay(espera);
  }

  for (int i=255; i>0; i--)
  {
    analogWrite(led_pin, i);
    delay(espera);
  }
  
  

  
}
