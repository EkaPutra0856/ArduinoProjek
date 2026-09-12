const int SENSOR_API = 2;
const int LED = 13;
const int BUZZER = 8;

void setup() {
  pinMode(SENSOR_API, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool apiTerdeteksi = digitalRead(SENSOR_API) == LOW;
  digitalWrite(LED, apiTerdeteksi ? HIGH : LOW);

  if (apiTerdeteksi) {
    tone(BUZZER, 1600);
    Serial.println("Peringatan: api terdeteksi");
  } else {
    noTone(BUZZER);
    Serial.println("Kondisi aman");
  }
  delay(200);
}
