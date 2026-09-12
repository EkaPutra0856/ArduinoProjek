#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int SS_PIN = 10;
const int RST_PIN = 9;
const int SERVO_PIN = 6;
const int BUZZER = 7;
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

void tampilkan(const char* baris1, const char* baris2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(baris1);
  lcd.setCursor(0, 1);
  lcd.print(baris2);
}

void setup() {
  SPI.begin();
  rfid.PCD_Init();
  servo.attach(SERVO_PIN);
  pinMode(BUZZER, OUTPUT);
  servo.write(0);
  lcd.init();
  lcd.backlight();
  tampilkan("Pintu RFID", "Tempelkan kartu");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  servo.write(90);
  tone(BUZZER, 1400, 200);
  tampilkan("Akses diterima", "Pintu terbuka");
  delay(3000);
  servo.write(0);
  tampilkan("Pintu terkunci", "Tempelkan kartu");
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
