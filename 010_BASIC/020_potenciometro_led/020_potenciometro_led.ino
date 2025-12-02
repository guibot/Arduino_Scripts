// declarar pin do potenciometro
int potentiometro_pin = A0;

// declarar pin do LED com PWM
int led_pin = 9;

// valor do potenciometro
int pot_val;

// valor de PWM - obtido por função map() - ver referencia
int pot_val_mapped;

void setup() {
  // abrir comunicação Serial
  Serial.begin(9600);
  // definir LED como OUTPUT
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // leitura do potenciometro
  pot_val = analogRead(potentiometro_pin); 

  //               map(value, fromLow, fromHigh, toLow, toHigh)
  pot_val_mapped = map(pot_val, 1023, 0, 100, 255);

  // output analogico
  analogWrite(led_pin, pot_val_mapped);

  // imprimir valores da leitura analógica
  Serial.print(pot_val);
  Serial.print("  ");
  Serial.println(pot_val_mapped);
}

/*
  // output analogico (PWM) - 0 a 255
  analogWrite(led_pin, 0);
  delay(1000);
  analogWrite(led_pin, 50);
  delay(1000);
  analogWrite(led_pin, 100);
  delay(1000);
  analogWrite(led_pin, 150);
  delay(1000);
  analogWrite(led_pin, 255);
  delay(1000);
*/
