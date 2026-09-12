#include <Servo.h>

const int RAIN = A0;
const int SERVO_PIN = 9;
const int BUZZER = 8;
const int BATAS_HUJAN = 600;
Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  bool hujan = analogRead(RAIN) < BATAS_HUJAN;
  servo.write(hujan ? 90 : 0);
  digitalWrite(BUZZER, hujan ? HIGH : LOW);
  delay(300);
}
