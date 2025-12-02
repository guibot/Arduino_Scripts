#include <EEPROM.h>
// https://www.youtube.com/watch?v=u4sghilWFWk

int bt_1_pin = 4;
int bt_1_state;
int bt_1_last_state = 1;

int bt_2_pin = 3;
int bt_2_state;
int bt_2_last_state = 1;

int virtual_bt_state;
int virtual_bt_last_state = 1;

void setup() {
  Serial.begin(9600);
  //writeStringIntoEEPROM(1, "Hello Arduino!");
  //delay(1000);
  //Serial.println(readStringFromEEPROM(1));

  pinMode(bt_1_pin, INPUT_PULLUP);
  pinMode(bt_2_pin, INPUT_PULLUP);
}

void loop() {
  bt_1_debounce(); // beata counter
  bt_2_debounce(); // reset eeprom
  
}
