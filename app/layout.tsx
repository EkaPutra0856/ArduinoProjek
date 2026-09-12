import type { Metadata } from "next";
import "./globals.css";

export const metadata: Metadata = {
  title: "RoboLab Al Azhar | Ekskul Robotika",
  description: "Portal belajar Arduino untuk ekskul robotika SMP Islam Al Azhar.",
};

export default function RootLayout({ children }: LayoutProps<"/">) {
  return <html lang="id" suppressHydrationWarning><body suppressHydrationWarning>{children}</body></html>;
}
