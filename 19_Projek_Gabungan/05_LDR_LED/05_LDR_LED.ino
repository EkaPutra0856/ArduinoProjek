const int LDR = A0;
const int LED = 8;
const int BATAS_GELAP = 500;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int cahaya = analogRead(LDR);
  digitalWrite(LED, cahaya < BATAS_GELAP ? HIGH : LOW);
  delay(200);
}
