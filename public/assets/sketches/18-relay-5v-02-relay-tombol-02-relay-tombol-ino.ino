const int TOMBOL = 2;
const int RELAY = 7;
bool relayMenyala = false;
int tombolTerakhir = HIGH;

void setup() {
  pinMode(TOMBOL, INPUT_PULLUP);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
}

void loop() {
  int tombolSekarang = digitalRead(TOMBOL);
  if (tombolTerakhir == HIGH && tombolSekarang == LOW) {
    relayMenyala = !relayMenyala;
    digitalWrite(RELAY, relayMenyala ? HIGH : LOW);
    delay(40);
  }
  tombolTerakhir = tombolSekarang;
}
