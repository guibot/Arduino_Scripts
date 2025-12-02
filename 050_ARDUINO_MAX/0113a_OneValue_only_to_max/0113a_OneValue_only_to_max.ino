int but; int EXbut;
void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(12, INPUT_PULLUP);
}
void loop() {
  int but = digitalRead(12);
  if (but == 1) {
    EXbut = 1;
  }
  if (but != EXbut and but == 0)
  {
    Serial.println(analogRead(A0));
    digitalWrite(6, HIGH);
  }
  EXbut = but; 
  delay(10);
  digitalWrite(6, LOW);
}
