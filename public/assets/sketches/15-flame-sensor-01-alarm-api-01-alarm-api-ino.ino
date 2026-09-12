const int FLAME = 2;
const int BUZZER = 8;

void setup() {
  pinMode(FLAME, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool apiTerdeteksi = digitalRead(FLAME) == LOW;
  digitalWrite(BUZZER, apiTerdeteksi ? HIGH : LOW);
  Serial.println(apiTerdeteksi ? "API TERDETEKSI" : "Aman");
  delay(200);
}
