/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 17:24:22
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-07 10:31:52
 * @FilePath: 04_SetAndReset_ByselfAPI\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

void delay(unsigned int count)
{
    for( ; count!=0;count--);

}

int main(void)
{


#if 0
    // 1.开启GPIO端口时钟
    RCC_AHB1ENR |=(1<<5);

    // 2.配置模式
    GPIOF_MODER &= ~(3<<(2*6));
    GPIOF_MODER |= (1<<(2*6));

    GPIOF_MODER &= ~(3<<(2*7));
    GPIOF_MODER |= (1<<(2*7));
    // 3.GPIO输出0/1 ODR寄存器或者BSRR
    
    while (1)
    {
        /* code */
        GPIOF_ODR |= (1<<7);
        GPIOF_ODR |= (1<<6);
        delay(0x0fffff);
        GPIOF_ODR &= ~(1<<6);
        delay(0x0fffff);
        GPIOF_ODR |= (1<<7);
        GPIOF_ODR |= (1<<6); 
        delay(0x0fffff);
        GPIOF_ODR &= ~(1<<7);
        delay(0x0fffff);

    }
    
#elif 1    //编写初始化结构体
// 1.开启GPIO端口时钟
    RCC_AHB1ENR |=(1<<5);

    // 2.配置模式
    // GPIOF->MODER &= ~(3<<(2*6));
    // GPIOF->MODER |= (1<<(2*6));
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7;
    GPIO_InitStruct.MODER=GPIO_Mode_OUT;
    GPIO_InitStruct.PUPDR=GPIO_PuPd_UP;
    GPIO_InitStruct.OTYPER=GPIO_OType_PP;
    GPIO_InitStruct.OSPEEDR=GPIO_Speed_2MHz;
    
    GPIO_Init(GPIOF,&GPIO_InitStruct);
    // GPIOF->MODER &= ~(3<<(2*7));
    // GPIOF->MODER |= (1<<(2*7));
    // 3.GPIO输出0/1 ODR寄存器或者BSRR
    
    while (1)
    { 
        /* code */
        
        // GPIOF->ODR |= (1<<7);
        GPIO_ResetBits(GPIOF, GPIO_Pin_7);
        delay(0x0fffff);
        GPIO_SetBits(GPIOF, GPIO_Pin_7);
        delay(0x0fffff);
        
   

    }

#endif 





}




void SystemInit(void)
{
								/* 空的*/
	
	
}







