int bt1_pin = 9;
int bt1_state;
int bt1_previous_state;

int rand_val;

void setup() {
  Serial.begin(9600);
  pinMode(bt1_pin, INPUT);
}

void loop() {

    rand_val = random(1000);

    bt1_state = digitalRead(bt1_pin);

    if (bt1_state != bt1_previous_state)
    {

      if (bt1_state == HIGH)
      {
      
      }
      else
      {
        Serial.println(rand_val);
      }
      delay(50);
  }
  bt1_previous_state = bt1_state;

}
