/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-08 19:54:19
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-09 14:28:53
 * @FilePath: \STM32CODE\06_FWLIB-TEMPALTE\User\LED\bsp_led.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "bsp_led.h"

void LED_GPIO_Config(void)
{
    // 1.打开GPIO时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
    // 2.定义GPIO初始化结构体
    GPIO_InitTypeDef GPIO_InitStruct;

    // 3.配置初始化结构体的成员
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed=GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;

    // 4.调用初始化函数，把配置好的结构体成员参数写入寄存器
    GPIO_Init(GPIOF,&GPIO_InitStruct);


    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7;
    GPIO_Init(GPIOF,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8;
    GPIO_Init(GPIOF,&GPIO_InitStruct);
    
}


