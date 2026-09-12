const int SENSOR_IR = 2;
const int LED = 13;
const int BUZZER = 8;

void setup() {
  pinMode(SENSOR_IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool bendaTerdeteksi = digitalRead(SENSOR_IR) == LOW;
  digitalWrite(LED, bendaTerdeteksi ? HIGH : LOW);

  if (bendaTerdeteksi) {
    tone(BUZZER, 900);
    Serial.println("Benda terdeteksi");
  } else {
    noTone(BUZZER);
    Serial.println("Jalur kosong");
  }
  delay(200);
}
