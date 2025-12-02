// porta do led
int led_azul_pin = 3;

// porta do potenciometro
int potenciometro_pin = A0;

// intensidade do led
int intensidade;


void setup() {
  // inicialização da comunicação série
  Serial.begin(9600);

  // declaração do led como saída de voltagem
  pinMode(led_azul_pin, OUTPUT);

}

void loop() {

  // mapeamento do valor do potenciometro que vai de 0 a 1023
  // para os valores do PWM que vão de 0 a 255
  intensidade = map(analogRead(A0), 0, 1023, 0, 255);

  // amostragem do valor na consola
  Serial.println(intensidade);

  // escrita analógica do led com a mudança de intensidade
  analogWrite(led_azul_pin, intensidade);
  

}
