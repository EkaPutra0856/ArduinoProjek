#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

const int SS_PIN = 10;
const int RST_PIN = 9;
const int BUZZER = 8;
MFRC522 rfid(SS_PIN, RST_PIN);
Servo servo;

void setup() {
  SPI.begin();
  rfid.PCD_Init();
  servo.attach(6);
  pinMode(BUZZER, OUTPUT);
  servo.write(0);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }
  servo.write(90);
  tone(BUZZER, 1200, 200);
  delay(3000);
  servo.write(0);
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
