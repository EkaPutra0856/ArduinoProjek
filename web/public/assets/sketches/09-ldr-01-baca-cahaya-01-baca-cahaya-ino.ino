const int LDR = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Nilai cahaya: ");
  Serial.println(analogRead(LDR));
  delay(500);
}
