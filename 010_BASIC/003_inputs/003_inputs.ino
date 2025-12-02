int botao_pin = 2;

int estado_botao;

void setup() {
  Serial.begin(9600);
  pinMode(botao_pin, INPUT_PULLUP);

}

void loop() {

  estado_botao = digitalRead(botao_pin);

  Serial.println(estado_botao);

}
