"use client";

import Image from "next/image";
import { useMemo, useState } from "react";
import materialData from "@/data/materials.json";

type Chapter = (typeof materialData.chapters)[number];
type Sketch = Chapter["sketches"][number];
const chapters = materialData.chapters as Chapter[];
const filters = ["Semua", "Pemula", "Komponen", "Projek"];

function cleanMarkdown(markdown: string) {
  return markdown.replace(/^#{1,6}\s*/gm, "").replace(/[*`]/g, "").trim();
}

export default function Home() {
  const [activeFilter, setActiveFilter] = useState("Semua");
  const [query, setQuery] = useState("");
  const [selected, setSelected] = useState<Chapter>(chapters[0]);
  const [selectedSketch, setSelectedSketch] = useState<Sketch>(chapters[0].sketches[0]);
  const [copied, setCopied] = useState(false);

  const visibleChapters = useMemo(() => chapters.filter((chapter) => {
    const matchesFilter = activeFilter === "Semua" || chapter.category === activeFilter;
    const haystack = `${chapter.title} ${chapter.description} ${chapter.readme}`.toLowerCase();
    return matchesFilter && haystack.includes(query.toLowerCase());
  }), [activeFilter, query]);

  function selectChapter(chapter: Chapter) {
    setSelected(chapter);
    setSelectedSketch(chapter.sketches[0]);
    document.querySelector("#detail")?.scrollIntoView({ behavior: "smooth", block: "start" });
  }

  function selectSketch(sketch: Sketch) {
    setSelectedSketch(sketch);
    setCopied(false);
    window.setTimeout(() => document.querySelector("#kode")?.scrollIntoView({ behavior: "smooth", block: "start" }), 0);
  }

  async function copyCode() {
    try {
      await navigator.clipboard.writeText(selectedSketch.code);
    } catch {
      const textArea = document.createElement("textarea");
      textArea.value = selectedSketch.code;
      document.body.appendChild(textArea);
      textArea.select();
      document.execCommand("copy");
      textArea.remove();
    }
    setCopied(true);
    window.setTimeout(() => setCopied(false), 1600);
  }

  return <main>
    <nav className="nav-shell"><a className="brand" href="#top"><span className="brand-mark">R</span><span>Robo<span className="accent">Lab</span></span></a><div className="nav-links"><a href="#materi">Materi</a><a href="#detail">Studio kode</a><a href="#tentang">Tentang ekskul</a></div><a className="nav-cta" href="#materi">Mulai belajar <span>↗</span></a></nav>

    <section className="hero" id="top"><div className="hero-copy"><p className="eyebrow">Ekskul Robotika · SMP Islam Al Azhar</p><h1>Materi<br /><em>praktik Arduino.</em></h1><p className="hero-text">Catatan belajar untuk mengenal komponen, merangkai alat, dan mencoba sketch Arduino Uno di meja praktik.</p><div className="hero-actions"><a className="button-primary" href="#materi">Lihat materi <span>↓</span></a><a className="text-link" href="#kode">Buka sketch <span>→</span></a></div></div><div className="hero-visual"><Image className="hero-photo" src={chapters[0].image ?? "/assets/01_Arduino_Dasar/gambar/arduino_dasar.jpg"} alt="Arduino untuk praktik dasar" width={620} height={420} priority unoptimized /><div className="photo-note">01 / Arduino Uno<br /><span>alat dasar praktik</span></div></div></section>

    <section className="stats"><div><strong>{materialData.chapterCount}</strong><span>bab materi</span></div><div><strong>{materialData.sketchCount}</strong><span>sketch asli</span></div><div><strong>18</strong><span>alat & komponen</span></div><p>Semua bersumber dari<br /><b>folder praktik Arduino.</b></p></section>

    <section className="content-section" id="materi"><div className="section-heading"><div><p className="eyebrow">01 / Daftar materi</p><h2>Bab dan alat<br /><em>untuk dicoba.</em></h2></div><p className="section-intro">Pilih bab untuk melihat gambar alat, panduan koneksi, dan sketch yang tersedia di folder praktik.</p></div><div className="toolbar"><div className="filters">{filters.map((filter) => <button type="button" key={filter} className={activeFilter === filter ? "filter active" : "filter"} onClick={() => setActiveFilter(filter)}>{filter}</button>)}</div><label className="search"><span>⌕</span><input value={query} onChange={(event) => setQuery(event.target.value)} placeholder="Cari alat atau materi..." /></label></div><div className="lesson-grid">{visibleChapters.map((chapter) => <button type="button" key={chapter.id} className={`lesson-card ${chapter.category === "Pemula" ? "mint" : chapter.category === "Komponen" ? "sky" : chapter.number === "19" ? "sun" : "ink"} ${selected.id === chapter.id ? "selected" : ""}`} onClick={() => selectChapter(chapter)}><div className="card-top"><span className="lesson-number">{chapter.number}</span><span className="card-arrow">↗</span></div>{chapter.image ? <Image className="card-image" src={chapter.image} alt={chapter.title} width={420} height={180} unoptimized /> : <div className="card-image card-image-empty">NO IMAGE</div>}<div><span className="lesson-tag">{chapter.category} · {chapter.sketches.length} sketch</span><h3>{chapter.title}</h3><p>{chapter.description}</p></div><span className="card-footer">Buka materi <span>→</span></span></button>)}</div>{visibleChapters.length === 0 && <p className="empty">Belum ada materi yang cocok. Coba kata kunci lain.</p>}</section>

    <section className="detail-section" id="detail"><a className="back-to-materials" href="#materi"><span>←</span> Kembali ke daftar alat</a><div className="detail-heading"><p className="eyebrow">02 / Detail materi</p><h2>{selected.title}<br /><em>catatan praktik.</em></h2><p>{selected.description}</p></div><div className="detail-body">{selected.image && <Image className="detail-image" src={selected.image} alt={`Alat ${selected.title}`} width={720} height={420} unoptimized />}{selected.readme && <div className="readme-box"><span className="mini-label">CATATAN & KONEKSI</span><p>{cleanMarkdown(selected.readme)}</p></div>}<div className="sketch-list"><div className="mini-label">FILE SKETCH PROYEK</div>{selected.sketches.map((sketch) => <button type="button" key={sketch.id} className={selectedSketch.id === sketch.id ? "sketch-button active" : "sketch-button"} onClick={() => selectSketch(sketch)}><span>{sketch.title}</span><small>{sketch.filename}</small><b>↗</b></button>)}{selected.relatedSketches.length > 0 && <><div className="related-sketch-label">KODE ALAT TERKAIT</div>{selected.relatedSketches.map((sketch) => <button type="button" key={sketch.id} className={selectedSketch.id === sketch.id ? "sketch-button related active" : "sketch-button related"} onClick={() => selectSketch(sketch)}><span>{sketch.title}</span><small>{sketch.filename}</small><b>↗</b></button>)}</>}</div></div></section>

    <section className="code-section" id="kode"><a className="back-to-materials" href="#materi"><span>←</span> Kembali ke daftar alat</a><div className="code-heading"><p className="eyebrow">03 / File sketch</p><h2>Lihat kode<br /><em>dan coba di IDE.</em></h2><p>{selectedSketch.filename} · file ini diambil langsung dari materi praktik. Pilih file lain di atas untuk membandingkan eksperimen.</p></div><div className="code-window"><div className="window-bar"><div className="window-dots"><i /><i /><i /></div><span>{selectedSketch.filename}</span><div className="code-actions"><button type="button" onClick={copyCode}>{copied ? "Tersalin!" : "Salin kode"} <span>□</span></button><a href={selectedSketch.path} download={selectedSketch.filename}>Unduh .ino <span>↓</span></a></div></div><pre><code>{selectedSketch.code}</code></pre></div></section>

    <section className="about-section" id="tentang"><div className="about-number">04</div><div><p className="eyebrow">Tentang ruang ini</p><h2>Robotika bukan<br /><em>sekadar kabel.</em></h2></div><p>Di sini kamu belajar mengubah pertanyaan menjadi percobaan. Membaca sensor, memberi instruksi, menguji, gagal, lalu mencoba lagi. Semua materi disusun untuk ekskul Robotika SMP Islam Al Azhar dan menggunakan Arduino Uno sebagai titik berangkat.</p></section>
    <footer><a className="brand" href="#top"><span className="brand-mark">R</span><span>Robo<span className="accent">Lab</span></span></a><span>Ekskul Robotika · SMP Islam Al Azhar</span><span>Made to tinker with curiosity.</span></footer>
  </main>;
}
