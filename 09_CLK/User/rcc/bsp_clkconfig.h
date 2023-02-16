#ifndef _BSP_CLKCONFIG_H
#define _BSP_CLKCONFIG_H

#include "stm32f4xx.h"

void USer_SetSysClock(void);
void HSE_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q);
void HSI_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q);


void MCO1_GPIO_Congig(void);
void MCO2_GPIO_Congig(void);




#endif

