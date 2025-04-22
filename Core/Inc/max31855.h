#ifndef MAX31855_H
#define MAX31855_H

#include "main.h"

void MAX31855_Init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* csPort, uint16_t csPin);
float MAX31855_BacaCelcius(void);

#endif
