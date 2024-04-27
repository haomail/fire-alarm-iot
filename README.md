## Rancang Bangun Alat Mitigasi Kebakaran Berbasis Internet Of Things Sebagai Wujud Peningkatan Infrastruktur Terintegrasi Di Laboratorium Kimia Sma Negeri 34 Jakarta

**Project ini dibuat berkelompok dalam penyelesaian Pengabdian Kepada Masyarakat mata kuliah wajib universitas (MKWU) pada April 2024 dengan dosen pembina MKWU UPNVJ**

## Tujuan
Menyediakan sistem notifikasi melalui sensor kebakaran otomatis kepada pihak sekolah ketika terdeteksi potensi kebakaran yang memungkinkan respons cepat dan efisien dalam pengambilan tindakan pencegahan dan evakuasi
## Cara Kerja
 1. Sensor Suhu DHT22, Sensor Gas MQ135, dan Sensor Api akan bekerja secara realtime dalam mendeteksi Suhu, Gas, dan Api disekitar
 2. Batas Suhu adalah 40C, Gas 1100, dan Api 200
 3. Pengguna dapat menggunakan keyword **on** atau **off** untuk mengontrol Alarm Kebakaran melalui bot Telegram
 4. Jika Suhu diatas 40 atau Gas diatas 1100 dan Api dibawah 200 maka Alarm Kebakaran akan menyalakan buzzernya dan mengirimkan notifikasi ke telegram
