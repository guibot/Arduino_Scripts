int motorA_pin1 = 6;
int motorA_pin2 = 7;

int motorB_pin1 = 4;
int motorB_pin2 = 5;


void setup() {
  pinMode(motorA_pin1, OUTPUT);
  pinMode(motorA_pin2, OUTPUT);

  pinMode(motorB_pin1, OUTPUT);
  pinMode(motorB_pin2, OUTPUT);

}

void loop() {
  digitalWrite(motorA_pin1, HIGH);
  digitalWrite(motorA_pin2, LOW);

  digitalWrite(motorB_pin1, HIGH);
  digitalWrite(motorB_pin2, LOW);

  delay(2500);

  digitalWrite(motorA_pin1, LOW);
  digitalWrite(motorA_pin2, HIGH);

  digitalWrite(motorB_pin1, LOW);
  digitalWrite(motorB_pin2, HIGH);

  delay(2500);

  

}
