# Projek Kompleks Arduino

Setiap proyek di folder ini menggunakan minimal empat alat atau modul. Buka sketch dari subfoldernya masing-masing.

## Daftar proyek

1. Tong sampah otomatis: ultrasonic + servo + buzzer + LCD.
2. Pintu RFID aman: RFID + servo + buzzer + LCD.
3. Sistem keamanan rumah: getaran + flame sensor + buzzer + LED + LCD.
4. Penyiram tanaman pintar: soil moisture + relay + LCD + rain sensor.
5. Stasiun lingkungan: DHT11 + LDR + MQ-2 + LCD + buzzer.

## Library yang digunakan

- `LiquidCrystal I2C`
- `MFRC522`
- `DHT sensor library`
- `Adafruit Unified Sensor` sebagai dependency DHT11

Pasang melalui **Arduino IDE -> Library -> Manage Libraries**. Link dan catatan koneksi tersedia di README folder komponen terkait.

## Catatan keselamatan

- Semua modul harus memiliki GND yang sama.
- RC522 menggunakan 3.3V, bukan 5V.
- Relay hanya mengendalikan beban yang sesuai spesifikasi modul.
- Untuk pompa atau motor, gunakan catu daya eksternal yang sesuai.
- Nilai batas sensor seperti `BATAS_GAS`, `BATAS_GELAP`, dan `BATAS_HUJAN` perlu dikalibrasi.
