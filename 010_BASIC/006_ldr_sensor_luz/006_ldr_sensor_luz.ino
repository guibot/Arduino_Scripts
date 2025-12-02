void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  Serial.println( analogRead(A0));
  analogWrite(9, map(analogRead(A0), 0, 1023, 0, 255));
}
