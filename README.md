# 🔥 Boiler Safety System – STM32 Project

Proyek ini merupakan implementasi sistem *Functional Safety* pada **boiler pembangkit listrik tenaga uap** menggunakan mikrokontroler STM32. Sistem ini memantau **temperatur** dan **tekanan** dalam boiler menggunakan sensor digital dan memberikan kontrol terhadap **valve bahan bakar**, **valve steam**, serta **alarm buzzer** untuk menjaga keselamatan operasional

## 🚀 Fitur Utama

- 🔍 Monitoring temperatur (sensor MAX31855 via SPI)
- 💨 Monitoring tekanan (sensor Honeywell via I2C)
- ⚠️ Logika safety:
  - Jika **temperatur melebihi batas**, sistem akan **mengurangi laju pembukaan valve bahan bakar**.
  - Jika **tekanan melebihi batas**, **valve uap akan terbuka** dan buzzer menyala.
- 🧠 Logika kontrol direalisasikan dalam standar **fail-safe**, sesuai prinsip Functional Safety.

## 🛠️ Perangkat & Library yang Digunakan

### Perangkat Keras:
- Board: STM32 Nucleo F446RE
- Sensor Temperatur: MAX31855 (SPI)
- Sensor Tekanan: Honeywell Digital Pressure Sensor (I2C)
- Valve Bahan Bakar: dikontrol via PWM (TIM3 - PB1)
- Valve Steam: dikontrol via GPIO (PB0)
- Alarm/Buzzer: GPIO output (PB10)

### Perangkat Lunak:
- STM32CubeMX
- Keil uVision IDE (versi 5.38 atau terbaru)
- STM32Cube HAL Drivers

---

## ⚙️ Konfigurasi Pin STM32

| Pin STM32   | Fungsi                  |
|-------------|--------------------------|
| PB0         | Valve Steam (Output)     |
| PB1         | Valve Bahan Bakar (PWM)  |
| PB10        | Buzzer / Alarm           |
| SPI1        | Komunikasi dengan MAX31855 |
| I2C1        | Komunikasi dengan Honeywell |

---

## 🧪 Cara Menggunakan Program

### 1. **Clone Repository**
- git clone https://github.com/namakamu/BoilerSafety.git
**2. Buka dengan Keil uVision**
- Buka file BoilerSafety.uvprojx di folder utama.
- Pastikan STM32Pack sudah terinstal sesuai board (STM32F4 series).

**3. Build Project**
- Klik Rebuild (Ctrl + F7) untuk mem-build project.
- Pastikan tidak ada error saat kompilasi.

**4. Upload ke Board STM32**
- Hubungkan board via USB.
- Pastikan ST-Link terdeteksi.
- Klik Download (Ctrl + F8) untuk mengupload firmware ke board.

**5. Cek Output**
- Pantau output dari aktuator (valve dan buzzer).
- Cek nilai pembacaan dari debugger jika menggunakan serial monitor/semilog

📌 Catatan Penting
- Pastikan power supply sensor sesuai (3.3V atau 5V sesuai sensor).
- Periksa sambungan SPI/I2C dan pastikan alamat I2C sesuai konfigurasi sensor.
- Sistem menggunakan pendekatan fail-safe tanpa redundansi, sehingga ketika kondisi overheat/overpressure terdeteksi, aktuator langsung dikendalikan untuk mitigasi risiko.

📚 Lisensi
Proyek ini bersifat open-source untuk keperluan edukasi dan pengembangan sistem instrumentasi industrial.

👨‍🔧 Kontributor
Nama: Abi Hanifa, Yusuf Aldi Prasetyo, Aireka Maulana Erawan
