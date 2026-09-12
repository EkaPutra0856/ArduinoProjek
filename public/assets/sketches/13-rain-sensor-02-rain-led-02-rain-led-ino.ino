const int SENSOR_HUJAN = A0;
const int LED = 13;
const int BATAS_HUJAN = 600;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int nilaiHujan = analogRead(SENSOR_HUJAN);
  bool hujanTerdeteksi = nilaiHujan < BATAS_HUJAN;
  digitalWrite(LED, hujanTerdeteksi ? HIGH : LOW);

  Serial.print("Nilai sensor hujan: ");
  Serial.println(nilaiHujan);
  delay(300);
}
