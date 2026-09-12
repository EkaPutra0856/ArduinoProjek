const int TOMBOL = 2;
const int BUZZER = 8;

void setup() {
  pinMode(TOMBOL, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (digitalRead(TOMBOL) == LOW) {
    tone(BUZZER, 1000);
  } else {
    noTone(BUZZER);
  }
}
