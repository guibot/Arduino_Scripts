
int bt_1_counter;
int bt_2_counter;

void bt_1_debounce()
{
  bt_1_state = digitalRead(bt_1_pin);
  if (bt_1_state == 1 && bt_1_last_state == 0)
  {
    Serial.print(bt_1_counter++);
    Serial.println(" bt 1 released");
    //Serial.println(readStringFromEEPROM(1));
  }
  if (bt_1_state == 0 && bt_1_last_state == 1)
  {
    Serial.print(bt_1_counter++);
    Serial.println(" bt 1 pressed");
  }
  bt_1_last_state = bt_1_state;
}

void bt_2_debounce()
{
  bt_2_state = digitalRead(bt_2_pin);
  if (bt_2_state == 1 && bt_2_last_state == 0)
  {
    Serial.print(bt_2_counter++);
    Serial.println(" bt 2 released");
    //resetEEPROM();
    //writeStringIntoEEPROM(1, "Hello Arduino!");
  }
  if (bt_2_state == 0 && bt_2_last_state == 1)
  {
    Serial.print(bt_2_counter++);
    Serial.println(" bt 2 pressed");
    
  }
  bt_2_last_state = bt_2_state;
}
