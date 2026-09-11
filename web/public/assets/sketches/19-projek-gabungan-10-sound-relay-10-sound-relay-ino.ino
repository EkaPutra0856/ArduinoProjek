const int SOUND = 2;
const int RELAY = 7;

void setup() {
  pinMode(SOUND, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
}

void loop() {
  bool adaSuara = digitalRead(SOUND) == HIGH;
  digitalWrite(RELAY, adaSuara ? LOW : HIGH);
  delay(100);
}
