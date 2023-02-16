/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-09 09:29:59
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-09 11:31:16
 * @FilePath: \07_KEY_LED\User\KEY\bsp_key.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
void KEY_GPIO_Config(void);
uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
#define KEY_ON 1
#define KEY_OFF 0

#endif


