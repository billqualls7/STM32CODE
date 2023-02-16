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
#include "bsp_exti.h"

#include "bsp_systick.h"

//void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	
	//EXTI_Key_Config();
	SysTick_Init();
	/* ����LED�� */
	while (1)
	{
		LED1(ON);
		SysTick_Delay_Ms(500);
		LED1(OFF);
		SysTick_Delay_Ms(500);
	}
}

//void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
//{
//	for(; nCount != 0; nCount--);
//}
/*********************************************END OF FILE**********************/

