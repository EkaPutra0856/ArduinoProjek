const int RAIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int nilai = analogRead(RAIN);
  Serial.print("Nilai sensor hujan: ");
  Serial.println(nilai);
  delay(500);
}
