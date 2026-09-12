#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int nilai = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print("Nilai A0:       ");
  lcd.setCursor(0, 1);
  lcd.print(nilai);
  lcd.print("        ");
  delay(250);
}
