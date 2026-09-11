const int GETARAN = 2;
const int BUZZER = 8;

void setup() {
  pinMode(GETARAN, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool adaGetaran = digitalRead(GETARAN) == HIGH;
  digitalWrite(BUZZER, adaGetaran ? HIGH : LOW);
  Serial.println(adaGetaran ? "Getaran terdeteksi" : "Tidak ada getaran");
  delay(100);
}
