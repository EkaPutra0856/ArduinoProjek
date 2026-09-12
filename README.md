# Latihan Arduino per Komponen

Setiap folder komponen berisi beberapa sketch latihan. Buka satu subfolder contoh, lalu buka file `.ino` dengan Arduino IDE.

## Urutan belajar

1. `01_Arduino_Dasar`
2. `02_Servo_SG90`
3. `03_LCD_1602_I2C`
4. `04_Ultrasonic_HY-SRF05`
5. Sensor lain sesuai kebutuhan.

## Catatan umum

- Board: `Arduino Uno`.
- Tegangan logika: gunakan 5V untuk modul yang mendukung 5V.
- Semua rangkaian harus memiliki `GND` yang sama.
- Jika LCD hanya menampilkan kotak, atur trimpot kontras di belakang modul.
- Jika servo bergerak tidak stabil, gunakan catu daya 5V eksternal dan satukan GND eksternal dengan GND Arduino.
- Untuk Arduino IDE, setiap sketch sebaiknya dibuka dari foldernya sendiri.

## Portal web

Folder root juga merupakan aplikasi Next.js untuk portal materi Robotika.

### Jalankan lokal

```bash
npm install
npm run dev
```

Buka `http://localhost:3000`.

### Deploy ke Vercel

Import repository ini di Vercel dan gunakan pengaturan default Next.js. Root Directory harus dibiarkan kosong karena konfigurasi web sekarang berada di root repository.

Build lokal dapat dicek dengan `npm run lint` dan `npm run build`.

Script `scripts/sync-materials.mjs` membaca seluruh folder bab Arduino, lalu menyalin gambar dan sketch ke `public/assets` serta membuat `data/materials.json`. Script ini otomatis dijalankan sebelum `npm run dev` dan `npm run build`.
