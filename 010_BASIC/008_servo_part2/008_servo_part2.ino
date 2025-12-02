#include <Servo.h>

Servo servo1;
Servo servo2;

int botao_pin = 3;
int botao_estado;
int botao_estado_anterior;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(9);
  servo2.attach(10);

  

  pinMode(botao_pin, INPUT_PULLUP);

}

void loop() 
{
  botao_estado = digitalRead(botao_pin);

  if (botao_estado == 1 && botao_estado_anterior == 0)
  {
    abreGarra(); 
     botao_estado_anterior = 1;
  }

  if (botao_estado == 0 && botao_estado_anterior == 1)
  {
    fechaGarra(); 
    botao_estado_anterior = 0;
  }  
}

void abreGarra()
{
  Serial.println("abreGarra()");  
  servo1.write(90);
  servo2.write(90);
  
}

void fechaGarra()
{
  servo1.write(170);
  servo2.write(10);
  Serial.println("fechaGarra()");  
}
