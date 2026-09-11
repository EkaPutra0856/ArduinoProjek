#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int TRIG = 7;
const int ECHO = 8;
const int SERVO_PIN = 9;
const int BUZZER = 6;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

long bacaJarakCm() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long durasi = pulseIn(ECHO, HIGH, 30000);
  return durasi == 0 ? 999 : durasi * 0.0343 / 2;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(0);
  lcd.init();
  lcd.backlight();
  lcd.print("Tong Sampah");
  delay(1500);
  lcd.clear();
}

void loop() {
  long jarak = bacaJarakCm();
  bool tanganDekat = jarak < 20;
  servo.write(tanganDekat ? 90 : 0);
  digitalWrite(BUZZER, tanganDekat ? HIGH : LOW);
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(jarak);
  lcd.print(" cm    ");
  lcd.setCursor(0, 1);
  lcd.print(tanganDekat ? "Tutup terbuka   " : "Siap digunakan  ");
  delay(250);
}
