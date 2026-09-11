#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int SOIL = A0;
const int RAIN = A1;
const int RELAY = 7;
const int BATAS_KERING = 700;
const int BATAS_HUJAN = 600;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int tanah = analogRead(SOIL);
  int hujan = analogRead(RAIN);
  bool tanahKering = tanah > BATAS_KERING;
  bool sedangHujan = hujan < BATAS_HUJAN;
  bool pompaNyala = tanahKering && !sedangHujan;

  digitalWrite(RELAY, pompaNyala ? LOW : HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Tanah:");
  lcd.print(tanah);
  lcd.print(sedangHujan ? " Hujan " : " Cerah ");
  lcd.setCursor(0, 1);
  lcd.print(pompaNyala ? "Pompa: NYALA    " : "Pompa: MATI     ");
  delay(1000);
}
