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
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();

	/* ����LED�� */
	while (1)
	{
		PFout(6) = 0;
		Delay(0xFFFFFF);
		
		PFout(6) = 1;
		Delay(0xFFFFFF);
		
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

