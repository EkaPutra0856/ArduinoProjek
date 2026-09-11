const int TRIG = 9;
const int ECHO = 10;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long durasi = pulseIn(ECHO, HIGH, 30000);
  float jarak = durasi * 0.0343 / 2;

  if (durasi == 0) {
    Serial.println("Tidak ada pembacaan");
  } else {
    Serial.print("Jarak: ");
    Serial.print(jarak);
    Serial.println(" cm");
  }
  delay(500);
}
