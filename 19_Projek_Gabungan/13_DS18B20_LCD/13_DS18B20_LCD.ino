#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int ONE_WIRE_BUS = 2;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  sensor.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  sensor.requestTemperatures();
  float suhu = sensor.getTempCByIndex(0);
  lcd.setCursor(0, 0);
  lcd.print("Suhu DS18B20:");
  lcd.setCursor(0, 1);
  lcd.print(suhu);
  lcd.print(" C        ");
  delay(1000);
}
