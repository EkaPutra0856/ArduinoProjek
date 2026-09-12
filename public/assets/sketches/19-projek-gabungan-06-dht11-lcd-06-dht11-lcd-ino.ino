#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define PIN_DHT 2
#define JENIS_DHT DHT11
DHT dht(PIN_DHT, JENIS_DHT);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print(" C       ");
  lcd.setCursor(0, 1);
  lcd.print("Lembap: ");
  lcd.print(kelembapan);
  lcd.print("%      ");
  delay(2000);
}
