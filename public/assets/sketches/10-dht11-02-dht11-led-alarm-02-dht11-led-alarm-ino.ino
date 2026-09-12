#include <DHT.h>

#define PIN_DHT 2
#define JENIS_DHT DHT11
const int LED = 13;
const float BATAS_SUHU = 30.0;

DHT dht(PIN_DHT, JENIS_DHT);

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  if (isnan(suhu)) {
    Serial.println("Gagal membaca DHT11");
    delay(2000);
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" C");
  digitalWrite(LED, suhu >= BATAS_SUHU ? HIGH : LOW);
  delay(2000);
}
