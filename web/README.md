# RoboLab Al Azhar

Portal web materi ekskul Robotika SMP Islam Al Azhar, dibuat dengan Next.js, React, dan Tailwind CSS.

## Jalankan lokal

```bash
cd web
npm install
npm run dev
```

Buka `http://localhost:3000`.

## Deploy ke Vercel

1. Push repository ini ke GitHub.
2. Import repository tersebut di [Vercel](https://vercel.com/new).
3. Set **Root Directory** menjadi `web`.
4. Framework akan terdeteksi sebagai Next.js. Klik **Deploy**.

Build lokal dapat dicek dengan `npm run lint` dan `npm run build` dari folder `web`.

## Sumber materi

Script `scripts/sync-materials.mjs` membaca seluruh folder bab Arduino di satu level
di atas `web`, lalu menyalin gambar dan sketch ke `public/assets` serta membuat
`data/materials.json`. Script ini otomatis dijalankan sebelum `npm run dev` dan
`npm run build`, sehingga materi baru ikut tampil setelah ditambahkan ke repository.
