const int MQ2 = A0;
const int BUZZER = 8;
const int BATAS_ASAP = 450;

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int nilai = analogRead(MQ2);
  bool asapTinggi = nilai > BATAS_ASAP;
  digitalWrite(BUZZER, asapTinggi ? HIGH : LOW);
  Serial.println(asapTinggi ? "PERINGATAN ASAP" : "Udara normal");
  delay(300);
}
