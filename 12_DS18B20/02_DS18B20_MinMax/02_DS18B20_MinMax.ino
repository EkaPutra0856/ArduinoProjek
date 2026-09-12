#include <OneWire.h>
#include <DallasTemperature.h>

const int BUS_SUHU = 2;
OneWire oneWire(BUS_SUHU);
DallasTemperature sensor(&oneWire);
float suhuMinimum = 1000;
float suhuMaksimum = -1000;

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  sensor.requestTemperatures();
  float suhu = sensor.getTempCByIndex(0);
  if (suhu == DEVICE_DISCONNECTED_C) {
    Serial.println("Sensor tidak terhubung");
    delay(1000);
    return;
  }

  suhuMinimum = min(suhuMinimum, suhu);
  suhuMaksimum = max(suhuMaksimum, suhu);
  Serial.print("Sekarang: ");
  Serial.print(suhu);
  Serial.print(" C | Min: ");
  Serial.print(suhuMinimum);
  Serial.print(" C | Max: ");
  Serial.print(suhuMaksimum);
  Serial.println(" C");
  delay(1000);
}
