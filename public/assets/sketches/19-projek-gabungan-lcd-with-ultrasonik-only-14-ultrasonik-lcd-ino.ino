#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD pada alamat 0x27 dengan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Deklarasi pin untuk sensor ultrasonik
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Atur mode pin untuk sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Mulai komunikasi LCD
  lcd.init();
  lcd.backlight();
  
  // Tampilkan pesan awal
  lcd.setCursor(0, 0);
  lcd.print("Sensor Jarak");
  lcd.setCursor(0, 1);
  lcd.print("Memulai...");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration;
  int distance;

  // Pastikan pin Trig dalam keadaan LOW sebelum menembakkan sinyal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Tembakkan sinyal ultrasonik selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pantulan suara pada pin Echo
  duration = pulseIn(echoPin, HIGH);

  // Hitung jarak dalam centimeter (kecepatan suara = 340 m/s atau 0.034 cm/us)
  distance = duration * 0.034 / 2;

  // Tampilkan hasil jarak ke LCD
  lcd.setCursor(0, 0);
  lcd.print("Jarak saat ini:");
  
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm    "); // Tambahan spasi di belakang untuk menghapus sisa karakter lama

  // Jeda 0.5 detik sebelum membaca ulang
  delay(500); 
}