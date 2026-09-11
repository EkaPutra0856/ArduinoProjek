const int GETARAN = 2;
const int BUZZER = 8;
const int LED = 13;

void setup() {
  pinMode(GETARAN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  bool bergetar = digitalRead(GETARAN) == HIGH;
  digitalWrite(BUZZER, bergetar ? HIGH : LOW);
  digitalWrite(LED, bergetar ? HIGH : LOW);
  delay(100);
}
