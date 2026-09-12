#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int SOIL = A0;
const int BATAS_KERING = 700;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int nilai = analogRead(SOIL);
  lcd.setCursor(0, 0);
  lcd.print("Tanah: ");
  lcd.print(nilai);
  lcd.print("       ");
  lcd.setCursor(0, 1);
  lcd.print(nilai > BATAS_KERING ? "Kondisi: KERING" : "Kondisi: BASAH ");
  delay(500);
}