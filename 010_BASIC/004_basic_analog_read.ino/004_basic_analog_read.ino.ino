int sensor_pin = A0;
int sensor_valor;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
}

void loop() {
  sensor_valor = analogRead(sensor_pin);
  Serial.print(0);
  Serial.print(" ");
  Serial.print(1023);
  Serial.print(" ");
  Serial.println(sensor_valor);

}
