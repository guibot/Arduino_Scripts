int motorA_pin1 = 3;
int motorA_pin2 = 5;

int motorB_pin1 = 9;
int motorB_pin2 = 10;


void setup() {
  pinMode(motorA_pin1, OUTPUT);
  pinMode(motorA_pin2, OUTPUT);

  pinMode(motorB_pin1, OUTPUT);
  pinMode(motorB_pin2, OUTPUT);

}

void loop() {

  // FRENTE
  
  for (int i=0; i<255; i++)
  {
    analogWrite(motorA_pin1, i);
    analogWrite(motorA_pin2, LOW);

    analogWrite(motorB_pin1, i);
    analogWrite(motorB_pin2, LOW);
    delay(10);
  }

  for (int i=255; i>0; i--)
  {
    analogWrite(motorA_pin1, i);
    analogWrite(motorA_pin2, LOW);

    analogWrite(motorB_pin1, i);
    analogWrite(motorB_pin2, LOW);
    delay(10);
  }

  // TRÁS

  for (int i=0; i<255; i++)
  {
    analogWrite(motorA_pin1, LOW);
    analogWrite(motorA_pin2, i);

    analogWrite(motorB_pin1, LOW);
    analogWrite(motorB_pin2, i);
    delay(10);
  }

  for (int i=255; i>0; i--)
  {
    analogWrite(motorA_pin1, LOW);
    analogWrite(motorA_pin2, i);

    analogWrite(motorB_pin1, LOW);
    analogWrite(motorB_pin2, i);
    delay(10);
  }
  

  
  

}
