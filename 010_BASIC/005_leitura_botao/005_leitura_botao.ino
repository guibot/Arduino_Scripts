int botao_pin = 7;
int led_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(botao_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  Serial.println( digitalRead(botao_pin));
  digitalWrite(led_pin, !digitalRead(botao_pin));
}
