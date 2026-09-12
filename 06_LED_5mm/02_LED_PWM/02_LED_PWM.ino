const int POTENSIOMETER = A0;
const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int nilaiPotensiometer = analogRead(POTENSIOMETER);
  int terang = map(nilaiPotensiometer, 0, 1023, 0, 255);
  analogWrite(LED, terang);

  Serial.print("Kecerahan: ");
  Serial.println(terang);
  delay(50);
}
