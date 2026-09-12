const int MQ2 = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int nilai = analogRead(MQ2);
  Serial.print("Nilai MQ-2: ");
  Serial.println(nilai);
  delay(500);
}
