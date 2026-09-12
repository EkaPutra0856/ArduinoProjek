const int TOMBOL = 2;
const int LED = LED_BUILTIN;

bool ledMenyala = false;
int tombolTerakhir = HIGH;

void setup() {
  pinMode(TOMBOL, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  int tombolSekarang = digitalRead(TOMBOL);
  if (tombolTerakhir == HIGH && tombolSekarang == LOW) {
    ledMenyala = !ledMenyala;
    digitalWrite(LED, ledMenyala ? HIGH : LOW);
    delay(30);
  }
  tombolTerakhir = tombolSekarang;
}
