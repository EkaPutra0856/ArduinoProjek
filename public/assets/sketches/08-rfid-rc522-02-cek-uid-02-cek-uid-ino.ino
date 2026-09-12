#include <SPI.h>
#include <MFRC522.h>

const int PIN_SS = 10;
const int PIN_RST = 9;
MFRC522 rfid(PIN_SS, PIN_RST);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("Tempelkan kartu RFID");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  Serial.print("UID kartu: ");
  for (byte index = 0; index < rfid.uid.size; index++) {
    if (rfid.uid.uidByte[index] < 0x10) Serial.print("0");
    Serial.print(rfid.uid.uidByte[index], HEX);
    if (index < rfid.uid.size - 1) Serial.print(":");
  }
  Serial.println();
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay(500);
}
