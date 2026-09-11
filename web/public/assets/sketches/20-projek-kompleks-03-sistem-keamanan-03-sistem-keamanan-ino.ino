#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int GETARAN = 2;
const int FLAME = 3;
const int BUZZER = 8;
const int LED = 13;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(GETARAN, INPUT);
  pinMode(FLAME, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  bool getaran = digitalRead(GETARAN) == HIGH;
  bool api = digitalRead(FLAME) == LOW;
  bool bahaya = getaran || api;

  digitalWrite(BUZZER, bahaya ? HIGH : LOW);
  digitalWrite(LED, bahaya ? HIGH : LOW);
  lcd.setCursor(0, 0);
  lcd.print(bahaya ? "PERINGATAN!     " : "Rumah aman      ");
  lcd.setCursor(0, 1);
  if (api) {
    lcd.print("Api terdeteksi  ");
  } else if (getaran) {
    lcd.print("Getaran terdet. ");
  } else {
    lcd.print("Monitoring...   ");
  }
  delay(200);
}
