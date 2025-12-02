// import das bibliotecas Chrono e Ramp

// biblioteca Chrono serve de cronómetro para realizar operações baseadas em tempo 
// em vez do comando delay()
#include <Chrono.h> 

// biblioteca Ramp serve para suavizar uma transição de um valor para o outro
#include <Ramp.h>  

// instancias das bibliotecas
Chrono red_chrono, green_chrono, blue_chrono;
ramp red_ramp, green_ramp, blue_ramp; 

int red_random, green_random, blue_random;

// valores do led rgb
int red_val, green_val, blue_val;

// pins do led rgb
int red_pin = 11;
int green_pin = 10;
int blue_pin = 9;

void setup() {
  Serial.begin(9600);
}

void loop() 
{
  if (red_chrono.hasPassed(red_random)) 
  {
    red_ramp.go(random(255), 1000);
    red_random = random(1000);
    red_chrono.restart();
  }

  if (green_chrono.hasPassed(green_random)) 
  {
    green_ramp.go(random(255), 1000);
    green_random = random(1000);
    green_chrono.restart();
  }

  if (blue_chrono.hasPassed(blue_random)) 
  {
    blue_ramp.go(random(255), 1000);
    blue_random = random(1000);
    blue_chrono.restart();
  }

  analogWrite(red_pin, red_ramp.update());
  analogWrite(green_pin, green_ramp.update());
  analogWrite(blue_pin, blue_ramp.update());
 
}
