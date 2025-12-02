int led_azul_pin = 7;
int led_vermelho_pin = 11;

int potenciometro_pin = A0;

int espera_1 = 1000;

void setup() {
  // put your setup code here, to run once:
  // coloca aqui o teu código, ele só vai correr uma vez ao início
  Serial.begin(9600);
  
  pinMode(led_azul_pin, OUTPUT);
  pinMode(led_vermelho_pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // coloca aqui o teu código, ele vai correr repetidamente

  espera_1 = map(analogRead(A0), 0, 1023, 250, 5000);
  Serial.println(espera_1);

  
  digitalWrite(led_azul_pin, HIGH);

  delay(espera_1);

  digitalWrite(led_azul_pin, LOW);

  delay(espera_1);

  
}
