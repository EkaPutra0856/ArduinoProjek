#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String pesan = "  BELAJAR ARDUINO  ";

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  for (int posisi = 16; posisi > -pesan.length(); posisi--) {
    lcd.clear();
    lcd.setCursor(posisi, 0);
    lcd.print(pesan);
    delay(250);
  }
}
