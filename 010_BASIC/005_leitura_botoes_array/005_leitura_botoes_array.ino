/*
 * Guilherme Martins, 2022
 * 
 * ------------------ Português
 * 
 * Este programa faz uma leitura simples de dispositivos digitais
 * Este tipo de dispositivos tem apenas dois estados:
 * On-Off, Ligado-Desligado, Pressionado-Solto
 * 
 * Estes dispositivos podem ser:
 * Botões, Toggles, Switches, entre outros
 * 
 * ------------------ English
 * 
 * This program reads digital inputs
 * This type of device has only 2 possible states
 * On-Off, Pressed-Released
 * 
 * This devices can be:
 * Buttons, Toggles, Switches, among others
 * 
 */

/*
 * LIGAÇÕES AOS DISPOSITIVOS
 * 
 * DEVICES PIN CONNECTIONS:
 * 
 NEOPIXEL - 5
 LEDS - 29, 30, 31, 32
 POTS1- A10, A11, A12, A13
 POTS2 - A0, A1, A2, A3
 BTS1 - 24,25,26,27
 BTS2 - 9, 10, 11, 12
*/

/*
 * ligar 1os 4 bts
 * explicar que para adiccionar mais 4 teria que repetir todas as linhas
 * mostrar a array
 * mostrar que para alterar a sequencia dos prints, tenho so que alterar os pins na array
 */


int bt1_pin = 9;
int bt2_pin = 10;
int bt3_pin = 11;
int bt4_pin = 12;

#define BTS_TOTAL 8

int bt_pin[BTS_TOTAL] ={9, 10, 11, 12, 24, 25, 26, 27};

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < BTS_TOTAL; i++)
  {
    pinMode(bt_pin[i], INPUT);
  }
  
}

void loop() {
  
  for(int i = 0; i < BTS_TOTAL; i++)
  {
    Serial.print(digitalRead(bt_pin[i]));
    Serial.print("  ");  
  }
  
  Serial.println();
}
