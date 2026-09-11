#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define PIN_DHT 2
#define JENIS_DHT DHT11
const int LDR = A0;
const int MQ2 = A1;
const int BUZZER = 8;
const int BATAS_GAS = 450;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(PIN_DHT, JENIS_DHT);

void setup() {
  dht.begin();
  pinMode(BUZZER, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  float suhu = dht.readTemperature();
  int cahaya = analogRead(LDR);
  int gas = analogRead(MQ2);
  bool gasTinggi = gas > BATAS_GAS;
  digitalWrite(BUZZER, gasTinggi ? HIGH : LOW);

  lcd.setCursor(0, 0);
  lcd.print("S:");
  lcd.print(suhu);
  lcd.print("C L:");
  lcd.print(cahaya);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print(gasTinggi ? "Gas tinggi!     " : "Gas:");
  if (!gasTinggi) {
    lcd.print(gas);
    lcd.print("          ");
  }
  delay(2000);
}
