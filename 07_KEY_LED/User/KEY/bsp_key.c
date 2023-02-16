/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-09 09:29:51
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-09 14:22:48
 * @FilePath: \07_KEY_LED\User\KEY\bsp_key.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bsp_key.h"


void KEY_GPIO_Config(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC,ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOA,&GPIO_InitStruct);


    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_13;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOC,&GPIO_InitStruct);

}

uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
    if (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
    {
        while (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);
        return KEY_ON;
    }
    else return KEY_OFF;    
        
        

}

