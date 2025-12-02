int led_azul_pin = 7;
int led_vermelho_pin = 8;

void setup() {
  pinMode(led_azul_pin, OUTPUT);
  pinMode(led_vermelho_pin, OUTPUT);
}

void loop() {
  digitalWrite(led_azul_pin, HIGH);
  digitalWrite(led_vermelho_pin, LOW);
  delay(500);
  digitalWrite(led_azul_pin, LOW);
  digitalWrite(led_vermelho_pin, HIGH);
  delay(500);
  
}
