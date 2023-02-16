/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 15:46:11
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-04 17:22:03
 * @FilePath: \STM32CODE\LED-REG_2\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#include "stm32f4xx.h"


void delay(unsigned int count)
{
    for( ; count!=0;count--);

}

int main(void)
{
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
    
    





}




void SystemInit(void)
{
								/* 空的*/
	
	
}







