#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int TRIG = 7;
const int ECHO = 8;
const int SERVO_PIN = 9;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

long bacaJarakCm() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long durasi = pulseIn(ECHO, HIGH, 30000);
  return durasi == 0 ? 0 : durasi * 0.0343 / 2;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  servo.attach(SERVO_PIN);
  lcd.init();
  lcd.backlight();
}

void loop() {
  long jarak = bacaJarakCm();
  bool dekat = jarak > 0 && jarak < 15;
  servo.write(dekat ? 90 : 0);
  lcd.setCursor(0, 0);
  if (jarak == 0) {
    lcd.print("Jarak: Tidak ada");
  } else {
    lcd.print("Jarak: ");
    lcd.print(jarak);
    lcd.print(" cm   ");
  }
  lcd.setCursor(0, 1);
  lcd.print(dekat ? "Servo: TERBUKA " : "Servo: TUTUP   ");
  delay(300);
}