int sensor_pin = A0;
int sensor_valor;

void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  sensor_valor = analogRead(sensor_pin);
  Serial.println(sensor_valor);

}
