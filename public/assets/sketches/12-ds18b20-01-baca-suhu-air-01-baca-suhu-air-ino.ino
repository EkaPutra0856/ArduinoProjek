#include <OneWire.h>
#include <DallasTemperature.h>

const int ONE_WIRE_BUS = 2;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  sensor.requestTemperatures();
  float suhu = sensor.getTempCByIndex(0);
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" C");
  delay(1000);
}
