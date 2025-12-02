int led_azul_pin = 7;
int led_vermelho_pin = 11;

int espera_curto = 250;
int espera_longo = 1000;
int espera_apagado = 250;
int muda_de_letra = 1000;

void setup() {
  // put your setup code here, to run once:
  // coloca aqui o teu código, ele só vai correr uma vez ao início
  pinMode(led_azul_pin, OUTPUT);
  pinMode(led_vermelho_pin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // coloca aqui o teu código, ele vai correr repetidamente

  // A
  acenderLed(led_azul_pin, espera_curto);
  acenderLed(led_azul_pin, espera_longo);
  apagarLed(led_azul_pin, muda_de_letra);

  //R
  acenderLed(led_azul_pin, espera_curto);
  acenderLed(led_azul_pin, espera_longo);
  acenderLed(led_azul_pin, espera_curto);
  apagarLed(led_azul_pin, muda_de_letra);

  //D
  acenderLed(led_azul_pin, espera_longo);
  acenderLed(led_azul_pin, espera_curto);
  acenderLed(led_azul_pin, espera_curto);
  apagarLed(led_azul_pin, muda_de_letra);

  //U
  acenderLed(led_azul_pin, espera_curto);
  acenderLed(led_azul_pin, espera_curto);
  acenderLed(led_azul_pin, espera_longo);
  apagarLed(led_azul_pin, muda_de_letra);

  //I
  acenderLed(led_azul_pin, espera_curto);
  acenderLed(led_azul_pin, espera_curto);
  apagarLed(led_azul_pin, muda_de_letra);

  //N
  acenderLed(led_azul_pin, espera_longo);
  acenderLed(led_azul_pin, espera_curto);
  apagarLed(led_azul_pin, muda_de_letra);

  //O
  acenderLed(led_azul_pin, espera_longo);
  acenderLed(led_azul_pin, espera_longo);
  acenderLed(led_azul_pin, espera_longo);
  apagarLed(led_azul_pin, muda_de_letra);

  // FIM
  acenderLed(led_vermelho_pin, espera_longo);
  
}

void acenderLed(int _led, int _tempo_espera)
{
  digitalWrite(_led, HIGH);
  delay(_tempo_espera);
  apagarLed(_led, espera_curto);
}

void apagarLed(int _led, int _tempo_espera)
{
  digitalWrite(_led, LOW);
  delay(_tempo_espera);
}
