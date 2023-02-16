/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-11-16 13:15:18
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-11-16 15:03:55
 * @FilePath: \LED-REG\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "stm32f4xx.h"




int main(void)
{
 #if 0   
    // clock
    *(unsigned int *)( 0x40023800+0x30) |= (1<<5);

    /* 配置输出*/
    *(unsigned int *)(0x40021400+0x00) &= ~((0X03)<<(2*6));
    *(unsigned int *)(0x40021400+0x00) |= ~((0X01)<<(2*6));
    /* PF6 */
    *(unsigned int *)(0x40021400+0x14) |=(1<<6);

    /* PF6 */
    *(unsigned int *)(0x40021400+0x14) &=~(1<<6);
#elif 1
    // clock
    RCC_AHB1ENG |= (1<<5);

    /* 配置PF6输出*/
    GPIOF_MODER &= ~((0X03)<<(2*8));
    GPIOF_MODER |= ~((0X01)<<(2*8));
    /* PF6 */
    GPIOF_ODR |=(1<<8);

    /* PF6 */
    GPIOF_ODR &= ~(1<<8);
    

#endif
    



}




void SystemInit(void)
{
								/* 空的*/
	
	
}







