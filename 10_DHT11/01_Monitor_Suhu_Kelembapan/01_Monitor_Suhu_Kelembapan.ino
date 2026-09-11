#include <DHT.h>

#define PIN_DHT 2
#define JENIS_DHT DHT11
DHT dht(PIN_DHT, JENIS_DHT);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float kelembapan = dht.readHumidity();
  float suhu = dht.readTemperature();

  if (isnan(kelembapan) || isnan(suhu)) {
    Serial.println("Gagal membaca DHT11");
  } else {
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print(" C | Kelembapan: ");
    Serial.print(kelembapan);
    Serial.println(" %");
  }
  delay(2000);
}
