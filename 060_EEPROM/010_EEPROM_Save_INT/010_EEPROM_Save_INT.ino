#include <EEPROM.h>

// EEPROM tutorial, write INT into EEPROM
// https://www.youtube.com/watch?v=5x0nUy36Trs

void write2BytesIntIntoEEPROM(int address, int number)
{
  // this is our number in bytes
  // 10101010 01010101
  
  // this will shift the 1st 8 bytes to the right, and cut everything to the left
  //          10101010
  byte byte1 = (number >> 8) & 0xFF;  // 0xFF - is 255 in hex 
  
  // this cuts everything on the left
  //          01010101
  byte byte2 = number & 0xFF;

  EEPROM.write(address, byte1);
  EEPROM.write(address + 1, byte2);
}

int read2BytesIntFromEEPROM(int address)
{
  byte byte1 = EEPROM.read(address);
  byte byte2 = EEPROM.read(address + 1);

  // shift everything to the left, 8 zeros are added
  // 10101010 00000000
  // than we add byte2
  int result = (byte1 << 8) + byte2;
  return result;
}

void setup() {
  Serial.begin(9600);
  
  Serial.println(sizeof(int)); 
  // returns 2
  // an int is store on 2 bytes     

  write2BytesIntIntoEEPROM(1, 9999);
  
  delay(1000);
  Serial.println(read2BytesIntFromEEPROM(1));

}

void loop() {
  // put your main code here, to run repeatedly:

}
