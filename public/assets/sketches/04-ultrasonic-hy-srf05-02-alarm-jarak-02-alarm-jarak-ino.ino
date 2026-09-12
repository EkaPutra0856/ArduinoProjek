const int TRIG = 9;
const int ECHO = 10;
const int BUZZER = 8;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long durasi = pulseIn(ECHO, HIGH, 30000);
  float jarak = durasi * 0.0343 / 2;
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  if (jarak > 0 && jarak < 15) tone(BUZZER, 1200);
  else noTone(BUZZER);
  delay(200);
}
