/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 18:05:53
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-06 10:35:07
 * @FilePath: \STM32CODE\04_SetAndReset_ByselfAPI\stm32f4xx_gpio.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _STM32F4XX_GPIO_H 
#define _STM32F4XX_GPIO_H

#include "stm32f4xx.h"

#define GPIO_Pin_0     (uint16_t) 1<<0
#define GPIO_Pin_1     (uint16_t) 1<<1
#define GPIO_Pin_2     (uint16_t) 1<<2
#define GPIO_Pin_3     (uint16_t) 1<<3
#define GPIO_Pin_4     (uint16_t) 1<<4
#define GPIO_Pin_5     (uint16_t) 1<<5
#define GPIO_Pin_6     (uint16_t) 1<<6
#define GPIO_Pin_7     (uint16_t) 1<<7
#define GPIO_Pin_8     (uint16_t) 1<<8
#define GPIO_Pin_9     (uint16_t) 1<<9
#define GPIO_Pin_10    (uint16_t) 1<<10
#define GPIO_Pin_11    (uint16_t) 1<<11
#define GPIO_Pin_12    (uint16_t) 1<<12
#define GPIO_Pin_13    (uint16_t) 1<<13
#define GPIO_Pin_14    (uint16_t) 1<<14
#define GPIO_Pin_15    (uint16_t) 1<<15
#define GPIO_Pin_A11   (uint16_t) 0xffff




void GPIO_SetBits(GOIP_TypeDef * GPIOx,uint16_t GPIO_Pin);
void GPIO_ResetBits(GOIP_TypeDef * GPIOx,uint16_t GPIO_Pin);

#endif



