 
 /*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 17:24:22
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-04 18:02:54
 * @FilePath: 04_SetAndReset_ByselfAPI\stm32f4xx.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
 
#ifndef  _STM32F4XX_H
#define  _STM32F4XX_H

#include <stdint.h>


/* 用来存放寄存器映射相关代码 */
#define GPIOF_BASE      ((unsigned int ) 0x40021400)
#define RCC_BASE      ((unsigned int ) 0x40023800)



#define GPIOF_MODER     *(unsigned int *)(GPIOF_BASE+0x00)
#define GPIOF_OTYPER    *(unsigned int *)(GPIOF_BASE+0x04)
#define GPIOF_ODR       *(unsigned int *)(GPIOF_BASE+0x14)


#define RCC_AHB1ENR     *(unsigned int *)(RCC_BASE+0x30)

// 外设寄存器结构体定义
// typedef unsigned int uint32_t;
// typedef unsigned short int uint16_t;
typedef struct 
{
    /* data */
    uint32_t MODER;
    uint32_t OTYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
    uint32_t IDR;
    uint32_t ODR;
    uint16_t BSRRL;
    uint16_t BSRRH;
    uint32_t LCKR;
    uint32_t AFRL;
    uint32_t AFRH;

}GOIP_TypeDef;

#define GPIOF  ((GOIP_TypeDef *)GPIOF_BASE)

#endif 