#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

// Batas maksimal
#define MAX_TEMP        100.0f
#define MAX_PRESSURE    10.0f

// Variabel simulasi untuk debug (bisa dilihat di Watch Window)
volatile float currentTemperature = 0.0f;
volatile float currentPressure = 0.0f;
volatile bool valveSteamState = false;
volatile uint8_t valveBahanBakarPWM = 0;
volatile bool alarmState = false;

// Fungsi pengganti kontrol aktuator (simulasi)
void SetValveSteam(bool state) {
    valveSteamState = state;
}

void SetValveBahanBakarPWM(uint8_t duty) {
    valveBahanBakarPWM = duty;
}

void AktifkanAlarm(bool state) {
    alarmState = state;
}

// Fungsi logika safety
void CekSafety(float suhu, float tekanan) {
    if (suhu > MAX_TEMP) {
        // Overheat ? kurangi pembukaan bahan bakar dan aktifkan alarm
        SetValveBahanBakarPWM(20);  // Misalnya diturunkan jadi 20%
        AktifkanAlarm(true);
    } else {
        SetValveBahanBakarPWM(80);  // Normal operasi
        AktifkanAlarm(false);
    }

    if (tekanan > MAX_PRESSURE) {
        // Tekanan tinggi ? buka valve steam
        SetValveSteam(true);
        AktifkanAlarm(true);
    } else {
        SetValveSteam(false);
    }
}
void SystemClock_Config(void)
	{
    // Dummy function buat hindari error saat compile
    // Biasanya diisi pengaturan clock, tapi bisa dikosongin kalau cuma simulasi
	}
int main(void)
{

	HAL_Init();
	
		// Jika ada

    while (1)
    {
        // Simulasi input sensor (bisa kamu ubah manual waktu debug)
        // Misal di awal nilai default
        currentTemperature = 80.0f;
        currentPressure = 9.0f;

        // Cek safety
        CekSafety(currentTemperature, currentPressure);

        // Delay simulasi
        HAL_Delay(1000);
    }
}
