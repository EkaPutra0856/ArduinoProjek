const int RELAY = 7;

void setup() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
}

void loop() {
  digitalWrite(RELAY, LOW);
  delay(2000);
  digitalWrite(RELAY, HIGH);
  delay(2000);
}
