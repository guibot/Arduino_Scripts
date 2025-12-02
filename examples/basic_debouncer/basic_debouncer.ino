#include <Debouncer.h>

Debouncer debouncer1(2);
Debouncer debouncer2(4);
Debouncer debouncer3(6);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(debouncer1.updater());
  Serial.print("  ");
  Serial.print(debouncer2.updater());
  Serial.print("  ");
  Serial.print(debouncer3.updater());
  Serial.println("  ");
}
