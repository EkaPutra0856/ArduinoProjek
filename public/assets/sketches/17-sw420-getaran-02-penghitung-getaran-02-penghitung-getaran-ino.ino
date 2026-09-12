const int SENSOR_GETARAN = 2;
const int LED = 13;
unsigned long jumlahGetaran = 0;
int statusSebelumnya = LOW;

void setup() {
  pinMode(SENSOR_GETARAN, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int statusSekarang = digitalRead(SENSOR_GETARAN);
  if (statusSekarang == HIGH && statusSebelumnya == LOW) {
    jumlahGetaran++;
    digitalWrite(LED, HIGH);
    Serial.print("Jumlah getaran: ");
    Serial.println(jumlahGetaran);
  }
  if (statusSekarang == LOW) digitalWrite(LED, LOW);
  statusSebelumnya = statusSekarang;
  delay(20);
}
