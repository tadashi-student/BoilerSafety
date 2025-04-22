#include "max31855.h"

static SPI_HandleTypeDef *spiHandle;
static GPIO_TypeDef* cs_GPIO_Port;
static uint16_t cs_Pin;

void MAX31855_Init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* csPort, uint16_t csPin) {
    spiHandle = hspi;
    cs_GPIO_Port = csPort;
    cs_Pin = csPin;
}

float MAX31855_BacaCelcius(void) {
    uint8_t rxData[4];
    uint32_t rawValue = 0;

    HAL_GPIO_WritePin(cs_GPIO_Port, cs_Pin, GPIO_PIN_RESET);
    HAL_SPI_Receive(spiHandle, rxData, 4, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(cs_GPIO_Port, cs_Pin, GPIO_PIN_SET);

    rawValue = (rxData[0] << 24) | (rxData[1] << 16) | (rxData[2] << 8) | rxData[3];

    // Ambil 14-bit suhu dari bit 31 sampai 18
    int16_t tempRaw = (rawValue >> 18) & 0x3FFF;

    // Cek bit sign
    if (tempRaw & 0x2000) {
        tempRaw |= 0xC000;  // extend sign bit
    }

    return tempRaw * 0.25f;
}
