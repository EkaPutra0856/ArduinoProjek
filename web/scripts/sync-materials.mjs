import { cp, mkdir, readdir, readFile, rm, writeFile } from "node:fs/promises";
import path from "node:path";
import { fileURLToPath } from "node:url";

const webDir = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "..");
const sourceDir = path.resolve(webDir, "..");
const publicDir = path.join(webDir, "public", "assets");
const dataDir = path.join(webDir, "data");
const imageExtensions = new Set([".jpg", ".jpeg", ".png", ".webp"]);

function slugify(value) {
  return value.toLowerCase().replace(/[^a-z0-9]+/g, "-").replace(/^-|-$/g, "");
}

function titleize(value) {
  return value.replace(/^\d+_/, "").replaceAll("_", " ");
}

function categoryFor(number) {
  if (number <= 3) return "Pemula";
  if (number <= 18) return "Komponen";
  return "Projek";
}

async function findFirstImage(directory) {
  const entries = await readdir(directory, { withFileTypes: true });
  const images = entries.filter((entry) => entry.isFile() && imageExtensions.has(path.extname(entry.name).toLowerCase()));
  const image = images.find((entry) => entry.name.includes("-referensi")) || images.find((entry) => !entry.name.includes("-komponen"));
  return image ? path.join(directory, image.name) : null;
}

async function sync() {
  await rm(publicDir, { recursive: true, force: true });
  await mkdir(publicDir, { recursive: true });
  await mkdir(dataDir, { recursive: true });

  const entries = await readdir(sourceDir, { withFileTypes: true });
  const chapters = [];
  let sketchCount = 0;

  for (const entry of entries.sort((a, b) => a.name.localeCompare(b.name, undefined, { numeric: true }))) {
    if (!entry.isDirectory() || !/^\d{2}_/.test(entry.name) || entry.name === "web") continue;
    const chapterPath = path.join(sourceDir, entry.name);
    const number = Number(entry.name.slice(0, 2));
    const chapterSlug = slugify(entry.name);
    const chapterAssetDir = path.join(publicDir, chapterSlug);
    await mkdir(chapterAssetDir, { recursive: true });
    const chapterReadmePath = path.join(chapterPath, "README.md");
    let readme = "";
    try { readme = await readFile(chapterReadmePath, "utf8"); } catch {}

    const imagePath = await findFirstImage(path.join(chapterPath, "gambar")).catch(() => null);
    let image = null;
    if (imagePath) {
      const imageName = path.basename(imagePath);
      await cp(imagePath, path.join(chapterAssetDir, imageName));
      image = `/assets/${chapterSlug}/${imageName}`;
    }

    const childEntries = await readdir(chapterPath, { withFileTypes: true });
    const sketches = [];
    for (const child of childEntries.sort((a, b) => a.name.localeCompare(b.name, undefined, { numeric: true }))) {
      if (!child.isDirectory()) continue;
      const sketchFiles = (await readdir(path.join(chapterPath, child.name))).filter((file) => file.endsWith(".ino"));
      for (const sketchFile of sketchFiles) {
        const sketchPath = path.join(chapterPath, child.name, sketchFile);
        const code = await readFile(sketchPath, "utf8");
        const fileSlug = slugify(`${entry.name}-${child.name}-${sketchFile}`);
        const publicSketchPath = `/assets/sketches/${fileSlug}.ino`;
        await mkdir(path.join(publicDir, "sketches"), { recursive: true });
        await writeFile(path.join(publicDir, "sketches", `${fileSlug}.ino`), code);
        sketches.push({ id: fileSlug, title: titleize(child.name), filename: sketchFile, code, path: publicSketchPath });
        sketchCount += 1;
      }
    }

    chapters.push({
      id: chapterSlug,
      number: String(number).padStart(2, "0"),
      title: titleize(entry.name),
      category: categoryFor(number),
      description: readme.split("\n").find((line) => line.trim() && !line.startsWith("#"))?.trim() || `Materi praktik ${titleize(entry.name)}.`,
      readme,
      image,
      sketches,
    });
  }

  await writeFile(path.join(dataDir, "materials.json"), `${JSON.stringify({ generatedAt: new Date().toISOString(), chapterCount: chapters.length, sketchCount, chapters }, null, 2)}\n`);
  console.log(`Synced ${chapters.length} chapters and ${sketchCount} sketches.`);
}

sync().catch((error) => { console.error(error); process.exitCode = 1; });
