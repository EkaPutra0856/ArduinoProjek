const int LDR = A0;
const int LAMPU = 8;
const int BATAS_GELAP = 500;

void setup() {
  pinMode(LAMPU, OUTPUT);
}

void loop() {
  int nilaiCahaya = analogRead(LDR);
  digitalWrite(LAMPU, nilaiCahaya < BATAS_GELAP ? HIGH : LOW);
  delay(200);
}
