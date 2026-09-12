const int SOUND = 2;
const int LED = 13;

void setup() {
  pinMode(SOUND, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int suara = digitalRead(SOUND);
  digitalWrite(LED, suara == HIGH ? HIGH : LOW);
  Serial.println(suara == HIGH ? "Suara terdeteksi" : "Hening");
  delay(100);
}
