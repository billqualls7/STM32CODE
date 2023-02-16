/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ƶ����ˮ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  STM32 F407 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
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
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	//USer_SetSysClock();
	//HSE_SetSysClock(25, 336, 2, 7);
	HSI_SetSysClock(16, 336, 2, 7);
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	MCO1_GPIO_Congig();
	MCO2_GPIO_Congig();
	
	RCC_MCO1Config(RCC_MCO1Source_HSE,  RCC_MCO1Div_1);
	RCC_MCO2Config(RCC_MCO2Source_SYSCLK,  RCC_MCO2Div_1);
	/* ����LED�� */
	while (1)
	{
		LED1(ON);
		Delay(0x0FFFFF);		
		LED1(OFF);
		Delay(0x0FFFFF);
		
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

