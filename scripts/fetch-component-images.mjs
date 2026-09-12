import { mkdir, writeFile } from "node:fs/promises";
import path from "node:path";
import { fileURLToPath } from "node:url";

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "../..");
const components = [
  ["03_LCD_1602_I2C", ["16x2 LCD module.jpg", "LCD 16x2.jpg"]],
  ["04_Ultrasonic_HY-SRF05", ["HC-SR04.jpg", "SparkFun HC-SR04 Ultrasonic-Sensor 13959-01a.jpg"]],
  ["05_Buzzer_5V", ["Buzzer.jpg", "Piezoelectric buzzer.jpg"]],
  ["06_LED_5mm", ["LED - 5mm Green.jpg"]],
  ["07_IR_Obstacle", ["IR obstacle sensor.jpg", "IR obstacle avoidance sensor.jpg"]],
  ["08_RFID_RC522", ["RFID-RC522.jpg", "RFID-RC522 photo.jpg", "RFID module RC522.jpg"]],
  ["09_LDR", ["Photoresistor.jpg", "LDR.jpg"]],
  ["10_DHT11", ["DHT11.jpg", "DHT11 sensor.jpg"]],
  ["11_Soil_Moisture", ["Soil moisture sensor.jpg", "Soil moisture sensor module.jpg"]],
  ["13_Rain_Sensor", ["Rain sensor.jpg", "Rain sensor module.jpg"]],
  ["14_Sound_Sensor", ["Sound sensor.jpg", "Microphone sensor module.jpg"]],
  ["15_Flame_Sensor", ["Flame sensor.jpg", "Flame sensor module.jpg"]],
  ["17_SW420_Getaran", ["SW-420.jpg", "Vibration sensor module.jpg"]],
  ["18_Relay_5V", ["Relay module.jpg", "5V relay module.jpg"]],
];

function extensionFromType(contentType, url) {
  if (contentType.includes("png")) return ".png";
  if (contentType.includes("webp")) return ".webp";
  if (contentType.includes("jpeg")) return ".jpg";
  return path.extname(new URL(url).pathname).toLowerCase() || ".jpg";
}

async function fetchCandidate(title) {
  const pageUrl = `https://commons.wikimedia.org/wiki/Special:FilePath/${encodeURIComponent(title)}`;
  const response = await fetch(pageUrl, { redirect: "follow", headers: { "User-Agent": "RoboLab-AlAzhar/1.0" } });
  const contentType = response.headers.get("content-type") ?? "";
  if (!response.ok || !contentType.startsWith("image/")) return null;
  return { title, pageUrl, contentType, buffer: Buffer.from(await response.arrayBuffer()) };
}

async function replaceImages() {
  for (const [folder, candidates] of components) {
    let result = null;
    for (const candidate of candidates) {
      result = await fetchCandidate(candidate);
      if (result) break;
    }
    if (!result) throw new Error(`No direct image found for ${folder}: ${candidates.join(", ")}`);
    const extension = extensionFromType(result.contentType, result.pageUrl);
    const imageName = `${folder.toLowerCase()}-komponen${extension}`;
    const imageDir = path.join(root, folder, "gambar");
    await mkdir(imageDir, { recursive: true });
    await writeFile(path.join(imageDir, imageName), result.buffer);
    await writeFile(path.join(imageDir, "SUMBER.md"), `# Sumber gambar\n\n- Komponen: ${folder}\n- Gambar: [${result.title}](${result.pageUrl})\n- File yang dipakai: ${imageName}\n`);
    console.log(`${folder}: ${result.title}`);
  }
}

replaceImages().catch((error) => { console.error(error); process.exitCode = 1; });
