/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 18:05:36
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-06 10:32:37
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

