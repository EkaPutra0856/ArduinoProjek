const int MQ2 = A0;
const int BUZZER = 8;
const int LED = 13;
const int BATAS_ASAP = 450;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool asap = analogRead(MQ2) > BATAS_ASAP;
  digitalWrite(BUZZER, asap ? HIGH : LOW);
  digitalWrite(LED, asap ? HIGH : LOW);
  delay(200);
}
