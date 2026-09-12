const int SOIL = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int nilai = analogRead(SOIL);
  Serial.print("Nilai tanah: ");
  Serial.println(nilai);
  delay(500);
}
