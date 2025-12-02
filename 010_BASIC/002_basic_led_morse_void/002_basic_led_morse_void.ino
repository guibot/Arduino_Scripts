int led_azul_pin = 11;
int led_vermelho_pin = 7;

int periodo_curto = 250;
int pediodo_longo = 1000;
int periodo_apagado = 250;
int muda_de_letra = 1000;

void setup() {
  Serial.begin(9600);
  
  pinMode(led_azul_pin, OUTPUT);
  pinMode(led_vermelho_pin, OUTPUT);
}

void loop() {

  // A
  digitalWrite(led_azul_pin, HIGH);
  delay(periodo_curto);

  digitalWrite(led_azul_pin, LOW);
  delay(periodo_apagado);

  digitalWrite(led_azul_pin, HIGH);
  delay(periodo_longo);
  
  digitalWrite(led_azul_pin, LOW);
  delay(muda_de_letra);
  
}
