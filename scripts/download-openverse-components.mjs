import { mkdir, writeFile } from "node:fs/promises";
import path from "node:path";
import { fileURLToPath } from "node:url";

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "../..");
const selected = [
  ["03_LCD_1602_I2C", "eaa0d9d8-a06e-49e8-b735-f10bad0dd87e"],
  ["04_Ultrasonic_HY-SRF05", "ac32a837-5c2a-430f-8b81-8e3fb8155190"],
  ["05_Buzzer_5V", "8640cdb6-a4d8-4051-9084-70cd5d17c5f7"],
  ["06_LED_5mm", "dd549ab4-2d9c-40b4-94f4-95304038555a"],
  ["07_IR_Obstacle", "e3f699d1-0194-42aa-9f55-9ff757de4bdf"],
  ["08_RFID_RC522", "2432dc77-ba16-4757-bbda-a9344f16f396"],
  ["09_LDR", "d4eff555-a0d2-4f57-b4ae-2ca48e31bf12"],
  ["10_DHT11", "bcb99f77-7339-4ce6-8b6d-7e6b391e9362"],
  ["11_Soil_Moisture", "404e38be-0fa2-49ac-8582-e1ebf5a090b5"],
  ["13_Rain_Sensor", "e86dbbbe-e516-41d8-bd27-b1d95eae5152"],
  ["14_Sound_Sensor", "1d36dfce-922d-4781-b605-e1c05e0790b6"],
  ["15_Flame_Sensor", "6b92c378-88f3-46a9-9925-6b06a0ebc575"],
  ["17_SW420_Getaran", "942ed806-57d8-4d68-9cd0-8f993a41a162"],
  ["18_Relay_5V", "6e840553-c3f7-47dd-bdac-19bb0956a528"],
];

async function download(folder, id) {
  const response = await fetch(`https://api.openverse.org/v1/images/${id}/`);
  if (!response.ok) throw new Error(`${folder}: metadata request failed (${response.status})`);
  const item = await response.json();
  const imageUrl = item.thumbnail || item.url;
  let imageResponse = await fetch(imageUrl);
  if (!imageResponse.ok && item.url && item.url !== imageUrl) imageResponse = await fetch(item.url);
  if (!imageResponse.ok) throw new Error(`${folder}: image request failed (${imageResponse.status})`);
  const contentType = imageResponse.headers.get("content-type") || "image/jpeg";
  const extension = contentType.includes("png") ? ".png" : contentType.includes("webp") ? ".webp" : ".jpg";
  const imageName = `${folder.toLowerCase()}-referensi${extension}`;
  const imageDir = path.join(root, folder, "gambar");
  await mkdir(imageDir, { recursive: true });
  await writeFile(path.join(imageDir, imageName), Buffer.from(await imageResponse.arrayBuffer()));
  await writeFile(path.join(imageDir, "SUMBER.md"), `# Sumber gambar\n\n- Komponen: ${folder}\n- Judul: ${item.title}\n- Lisensi: ${item.license}\n- Sumber: [Openverse](${item.foreign_landing_url || item.source})\n- File yang dipakai: ${imageName}\n`);
  console.log(`${folder}: ${item.title} (${item.license})`);
}

for (const [folder, id] of selected) await download(folder, id);
