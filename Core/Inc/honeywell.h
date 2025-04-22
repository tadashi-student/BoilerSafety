#ifndef HONEYWELL_H
#define HONEYWELL_H

#include "main.h"

void Honeywell_Init(I2C_HandleTypeDef *hi2c, uint8_t alamat);
float Honeywell_BacaBar(void);

#endif
