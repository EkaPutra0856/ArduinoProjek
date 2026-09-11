const int TRIG = 7;
const int ECHO = 8;
const int BUZZER = 9;

long bacaJarak() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long durasi = pulseIn(ECHO, HIGH, 30000);
  return durasi == 0 ? 999 : durasi * 0.0343 / 2;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  long jarak = bacaJarak();
  if (jarak < 15) {
    tone(BUZZER, 1200);
  } else {
    noTone(BUZZER);
  }
  delay(100);
}
