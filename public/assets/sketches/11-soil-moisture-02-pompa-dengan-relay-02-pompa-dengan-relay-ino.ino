const int SOIL = A0;
const int RELAY = 7;
const int BATAS_KERING = 700;

void setup() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
}

void loop() {
  int nilai = analogRead(SOIL);
  bool tanahKering = nilai > BATAS_KERING;
  digitalWrite(RELAY, tanahKering ? LOW : HIGH);
  delay(1000);
}
