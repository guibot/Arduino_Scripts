int led_azul_pin = 11;
int led_vermelho_pin = 7;

int periodo_curto = 250;
int periodo_longo = 1000;
int apaga_led = 250;
int mudar_de_letra = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(led_azul_pin, OUTPUT);
  pinMode(led_vermelho_pin, OUTPUT);
}

void loop() {

  // A
  Serial.println("A");
  acenderLed(led_azul_pin, periodo_curto);
  acenderLed(led_azul_pin, periodo_longo);
  mudaLetra();

  //R
  Serial.println("R");
  acenderLed(led_azul_pin, periodo_curto);
  acenderLed(led_azul_pin, periodo_longo);
  acenderLed(led_azul_pin, periodo_curto);
  mudaLetra();

  //D
  Serial.println("D");
  acenderLed(led_azul_pin, periodo_longo);
  acenderLed(led_azul_pin, periodo_curto);
  acenderLed(led_azul_pin, periodo_curto);
  mudaLetra();

  //U
  Serial.println("U");
  acenderLed(led_azul_pin, periodo_curto);
  acenderLed(led_azul_pin, periodo_curto);
  acenderLed(led_azul_pin, periodo_longo);
  mudaLetra();

  //I
  Serial.println("I");
  acenderLed(led_azul_pin, periodo_curto);
  acenderLed(led_azul_pin, periodo_curto);
  mudaLetra();

  //N
  Serial.println("N");
  acenderLed(led_azul_pin, periodo_longo);
  acenderLed(led_azul_pin, periodo_curto);
  mudaLetra();

  //O
  Serial.println("O");
  acenderLed(led_azul_pin, periodo_longo);
  acenderLed(led_azul_pin, periodo_longo);
  acenderLed(led_azul_pin, periodo_longo);
  mudaLetra();
}




void acenderLed(int _pin, int _tempo_espera)
{
  digitalWrite(_pin, HIGH);
  delay(_tempo_espera);

  digitalWrite(_pin, LOW);
  delay(apaga_led);
}

void mudaLetra()
{
  digitalWrite(led_vermelho_pin, HIGH);
  delay(mudar_de_letra);
  digitalWrite(led_vermelho_pin, LOW);
  delay(mudar_de_letra);
}
