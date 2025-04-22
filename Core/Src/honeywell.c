#include "honeywell.h"

static I2C_HandleTypeDef *i2cHandle;
static uint8_t i2cAddress;

void Honeywell_Init(I2C_HandleTypeDef *hi2c, uint8_t alamat) {
    i2cHandle = hi2c;
    i2cAddress = alamat << 1;  // shift for HAL I2C
}

float Honeywell_BacaBar(void) {
    uint8_t buffer[2];
    HAL_I2C_Master_Receive(i2cHandle, i2cAddress, buffer, 2, HAL_MAX_DELAY);

    uint16_t raw = ((buffer[0] & 0x3F) << 8) | buffer[1]; // 14-bit data

    float pressure = ((float)raw - 1638.0f) * (10.0f / (14745.0f - 1638.0f));  // 0–10 bar
    return pressure;
}
