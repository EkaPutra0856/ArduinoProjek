#include <Servo.h>

const int TRIG = 7;
const int ECHO = 8;
const int SERVO_PIN = 9;
Servo servo;

long bacaJarakCm() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long durasi = pulseIn(ECHO, HIGH, 30000);
  if (durasi == 0) {
    return 999;
  }
  return durasi * 0.0343 / 2;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(0);
}

void loop() {
  long jarak = bacaJarakCm();
  servo.write(jarak < 15 ? 90 : 0);
  delay(200);
}