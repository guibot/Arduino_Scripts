void writeStringIntoEEPROM(int address, String str)
{
  byte len = str.length();
  // 1st address records the length of the string
  EEPROM.write(address, len);
  // the next address records the entire string
  for (int i = 0; i < len; i++)
  {
    Serial.print(address + 1 + i);
    Serial.print(" ");
    Serial.println(str[i]);
    EEPROM.write(address + 1 + i, str[i]);
  }
}

String readStringFromEEPROM(int address)
{
  int len = EEPROM.read(address);
  char data[len + 1];

  for (int i = 0; i < len; i++)
  {
    data[i] = EEPROM.read(address + 1 + i);
  }
  data[len] = '\0';

  return String(data);
}

void resetEEPROM()
{
  Serial.println("resetEEPROM");
  for (int i = 0; i < 255; i++)
    EEPROM.write(i, 0);
  delay(1000);
  readStringFromEEPROM(1);
}
