# LCD 1602 I2C

## Library

- Nama: `LiquidCrystal I2C`
- Arduino IDE: **Library Manager** -> cari `LiquidCrystal I2C` -> pilih library yang menyediakan `LiquidCrystal_I2C.h`
- Sumber: https://github.com/johnrickman/LiquidCrystal_I2C

Jika library tersebut tidak cocok, gunakan library lain yang tetap menyediakan header `LiquidCrystal_I2C.h`.

## Koneksi Arduino Uno

| LCD I2C | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

Alamat yang umum adalah `0x27`. Jika tidak tampil, coba `0x3F` pada kode.# LCD 1602 I2C

Koneksi umum Arduino Uno:

| LCD I2C | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

Jika alamat `0x27` tidak bekerja, coba `0x3F`. Pasang library `LiquidCrystal_I2C` dari Library Manager Arduino IDE.
