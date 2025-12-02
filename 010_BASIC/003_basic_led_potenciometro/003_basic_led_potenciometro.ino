// porta do led
int led_azul_pin = 7;

// porta do potenciometro
int potenciometro_pin = A0;

// valor de espera
int espera_1 = 1000;

void setup() {
  // inicialização da comunicação série
  Serial.begin(9600);

  // declaração do led como saída de voltagem
  pinMode(led_azul_pin, OUTPUT);

}

void loop() {
  // mapeamento do valor do potenciometro que vai de 0 a 1023
  // para os valores da espera que decidimos que iam ser de 250 a 5000
  espera_1 = map(analogRead(A0), 0, 1023, 250, 5000);

  // amostragem do valor "espera_1" na consola
  Serial.println(espera_1);

  // acende led
  digitalWrite(led_azul_pin, HIGH);
  // espera
  delay(espera_1);
  // apaga led
  digitalWrite(led_azul_pin, LOW);
  // espera
  delay(espera_1);

  
}
