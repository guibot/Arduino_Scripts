int red_pin = 11;
int green_pin = 10;
int blue_pin = 9;
int potenciometro_espera_pin = A0;
int potenciometro_incremento_pin = A5;
int espera;
int incremento;

void setup() {
  Serial.begin(9600);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

void loop() {

  espera = map(analogRead(potenciometro_espera_pin), 0, 1023, 1, 20);
  Serial.print("espera: ");
  Serial.print(espera);

  incremento = map(analogRead(potenciometro_incremento_pin), 0, 1023, 1, 20);
  Serial.print("  incremento: ");
  Serial.println(incremento);

  
  //Serial.println("acende");
  
  for (int i = 0; i < 255; i += incremento)
  {
    //Serial.println(i);
    analogWrite(red_pin, i);
    delay(espera);
  }

  //Serial.println("apaga");

  for (int i = 255; i > 0; i -= incremento)
  {
    //Serial.println(i);
    analogWrite(red_pin, i);
    delay(espera);
  }

}
