// botao 1
int bt1_pin = 9;
int bt1_state;
int bt1_previous_state;
int rand_val;

// potenciometros
int pot1_pin = A0;
int pot2_pin = A1;
int pot1_val, pot2_val;

void setup() {
  Serial.begin(9600);
  pinMode(bt1_pin, INPUT);
}

void loop() {

    // botao 1
    rand_val = random(1000);
    bt1_state = digitalRead(bt1_pin);
    if (bt1_state != bt1_previous_state)
    {
      if (bt1_state == HIGH)
      {
      
      }
      else
      {
        Serial.print("a");
        Serial.print("\t");
        Serial.println(rand_val);
        
      }
      delay(50);
  }
  bt1_previous_state = bt1_state;

  // pot 1
  pot1_val = analogRead(A0);
  pot2_val = analogRead(A1);
  
  Serial.print("b");
  Serial.print("\t");
  Serial.println(pot1_val);
  
  Serial.print("c");
  Serial.print("\t");
  Serial.println(pot2_val);

  delay(50);
  

}
