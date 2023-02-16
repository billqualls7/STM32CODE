/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 18:05:36
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-07 10:11:19
 * @FilePath: \STM32CODE\04_SetAndReset_ByselfAPI\stm32f4xx_gpio.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "stm32f4xx_gpio.h"

void GPIO_SetBits(GOIP_TypeDef * GPIOx,uint16_t GPIO_Pin)
{
    GPIOx->BSRRL=GPIO_Pin;
}

void GPIO_ResetBits(GOIP_TypeDef * GPIOx,uint16_t GPIO_Pin)
{
    GPIOx->BSRRH=GPIO_Pin;
}


void GPIO_Init(GOIP_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;
	
	/*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 16; pinpos++)
  {
		/*以下运算是为了通过 GPIO_InitStruct->GPIO_Pin 算出引脚号0-15*/
		
		/*经过运算后pos的pinpos位为1，其余为0，与GPIO_Pin_x宏对应。pinpos变量每次循环加1，*/
		pos = ((uint32_t)0x01) << pinpos;
   
		/* pos与GPIO_InitStruct->GPIO_Pin做 & 运算，若运算结果currentpin == pos，
		则表示GPIO_InitStruct->GPIO_Pin的pinpos位也为1，
		从而可知pinpos就是GPIO_InitStruct->GPIO_Pin对应的引脚号：0-15*/
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

		/*currentpin == pos时执行初始化*/
    if (currentpin == pos)
		{		
			/*GPIOx端口，MODER寄存器的GPIO_InitStruct->GPIO_Pin对应的引脚，MODER位清空*/
			GPIOx->MODER  &= ~(3 << (2 *pinpos));
		
			/*GPIOx端口，MODER寄存器的GPIO_Pin引脚，MODER位设置"输入/输出/复用输出/模拟"模式*/
			GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->MODER) << (2 *pinpos));

			/*GPIOx端口，PUPDR寄存器的GPIO_Pin引脚，PUPDR位清空*/
			GPIOx->PUPDR &= ~(3 << ((2 *pinpos)));
		
			/*GPIOx端口，PUPDR寄存器的GPIO_Pin引脚，PUPDR位设置"上/下拉"模式*/
			GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->PUPDR) << (2 *pinpos));		
		
			/*若模式为"输出/复用输出"模式，则设置速度与输出类型*/
			if ((GPIO_InitStruct->MODER == GPIO_Mode_OUT) || (GPIO_InitStruct->MODER == GPIO_Mode_AF))
			{
				/*GPIOx端口，OSPEEDR寄存器的GPIO_Pin引脚，OSPEEDR位清空*/
				GPIOx->OSPEEDR &= ~(3 << (2 *pinpos));
				/*GPIOx端口，OSPEEDR寄存器的GPIO_Pin引脚，OSPEEDR位设置输出速度*/
				GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->OSPEEDR) << (2 *pinpos));

				/*GPIOx端口，OTYPER寄存器的GPIO_Pin引脚，OTYPER位清空*/
				GPIOx->OTYPER  &= ~(1 << (pinpos)) ;
				/*GPIOx端口，OTYPER位寄存器的GPIO_Pin引脚，OTYPER位设置"推挽/开漏"输出类型*/
				GPIOx->OTYPER |= (uint16_t)(((uint16_t)GPIO_InitStruct->OTYPER) << (pinpos));
			}
		}
	}
}
