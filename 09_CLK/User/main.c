/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   控制多彩流水灯
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F407 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./rcc/bsp_clkconfig.h"

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x02000000+((addr & 0x000FFFFF)<<5)+(bitnum<<2)) 
#define MEM(addr) (*(volatile unsigned long*)(addr))

#define BIT_ADDR(addr,bitnum)  MEM(BITBAND(addr,bitnum))

#define GPIOF_ODR_ADDR     (GPIOF_BASE+0x14)

#define PFout(n)      BIT_ADDR(GPIOF_ODR_ADDR,n)








void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	//USer_SetSysClock();
	//HSE_SetSysClock(25, 336, 2, 7);
	HSI_SetSysClock(16, 336, 2, 7);
	/* LED 端口初始化 */
	LED_GPIO_Config();
	MCO1_GPIO_Congig();
	MCO2_GPIO_Congig();
	
	RCC_MCO1Config(RCC_MCO1Source_HSE,  RCC_MCO1Div_1);
	RCC_MCO2Config(RCC_MCO2Source_SYSCLK,  RCC_MCO2Div_1);
	/* 控制LED灯 */
	while (1)
	{
		LED1(ON);
		Delay(0x0FFFFF);		
		LED1(OFF);
		Delay(0x0FFFFF);
		
	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

