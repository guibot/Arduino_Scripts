int led_pin = 9;
int potenciometro_pin = A0;
int potenciometro_valor;
int valor_mapeado;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(potenciometro_pin, INPUT);
  Serial.begin(9600);
}

void loop() {

  potenciometro_valor = analogRead(potenciometro_pin);
  

                      //valor original, min entrada, max entrada, min saida, max saida
  valor_mapeado = map(potenciometro_valor, 0, 1023, 0, 255);  
  analogWrite(led_pin, valor_mapeado);

  Serial.print(potenciometro_valor);
  Serial.print("   ");
  Serial.println(valor_mapeado);
}
