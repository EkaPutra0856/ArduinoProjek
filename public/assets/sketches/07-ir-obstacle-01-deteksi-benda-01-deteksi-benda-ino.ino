const int SENSOR_IR = 2;
const int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_IR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int terdeteksi = digitalRead(SENSOR_IR);
  bool adaBenda = terdeteksi == LOW;
  digitalWrite(LED, adaBenda ? HIGH : LOW);
  Serial.println(adaBenda ? "Benda terdeteksi" : "Jalur kosong");
  delay(300);
}
