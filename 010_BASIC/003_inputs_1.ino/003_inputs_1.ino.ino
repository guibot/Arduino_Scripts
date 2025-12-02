int botao_pin = 3;
int botao_valor;

void setup()
{
  Serial.begin(9600);
  pinMode(botao_pin, INPUT_PULLUP);
}


void loop()
{
  botao_valor = digitalRead(botao_pin);
  Serial.println(botao_valor);
  
}
