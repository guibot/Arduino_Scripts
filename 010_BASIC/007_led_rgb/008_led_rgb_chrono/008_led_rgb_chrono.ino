#include <Chrono.h>

Chrono red_metro;
Chrono red_metro_update;

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
  if (red_metro.hasPassed(espera) ) {
    red_metro.restart();
    red_loop();
  }
  if (red_metro_update.hasPassed(5) ) {
    red_metro_update.restart();
    actualizar_variaveis();    
  }
}

int direccao = 0; // 0 = diminui , 1 = aumenta
int counter = 0;

void red_loop()
{
  if (direccao == 1 && counter < 255)
  {
    counter += incremento;
  }
  else
  {
    direccao = 0;
  }
  
  if (direccao == 0 && counter > 0)
  {
    counter -= incremento;
  }
  else
  {
    direccao = 1;
  }

  analogWrite(red_pin, counter);
  
  Serial.print("direccao: ");
  Serial.print(direccao);
  Serial.print(" counter: ");
  Serial.print(counter);
  
}

void actualizar_variaveis()
{
  espera = map(analogRead(potenciometro_espera_pin), 0, 1023, 1, 500);
    Serial.print("   espera: ");
    Serial.print(espera);
  incremento = map(analogRead(potenciometro_incremento_pin), 0, 1023, 1, 20);
    Serial.print("  incremento: ");
    Serial.println(incremento);
}
