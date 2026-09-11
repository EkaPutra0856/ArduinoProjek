#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int FLAME = 2;
const int BUZZER = 8;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(FLAME, INPUT);
  pinMode(BUZZER, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  bool api = digitalRead(FLAME) == LOW;
  digitalWrite(BUZZER, api ? HIGH : LOW);
  lcd.setCursor(0, 0);
  lcd.print(api ? "BAHAYA API     " : "Kondisi Aman    ");
  lcd.setCursor(0, 1);
  lcd.print(api ? "Alarm aktif     " : "Tidak ada api   ");
  delay(200);
}
