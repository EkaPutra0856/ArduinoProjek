const int SENSOR_SUARA = 2;
const int BUZZER = 8;

void setup() {
  pinMode(SENSOR_SUARA, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool suaraTerdeteksi = digitalRead(SENSOR_SUARA) == HIGH;
  if (suaraTerdeteksi) {
    tone(BUZZER, 1400, 120);
    Serial.println("Suara terdeteksi");
  }
  delay(150);
}
