/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-04 15:46:11
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-04 17:22:12
 * @FilePath: \STM32CODE\LED-REG_2\stm32f4xx.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

 
 
/* 用来存放寄存器映射相关代码 */
#define GPIOF_BASE      ((unsigned int ) 0x40021400)
#define RCC_BASE      ((unsigned int ) 0x40023800)



#define GPIOF_MODER     *(unsigned int *)(GPIOF_BASE+0x00)
#define GPIOF_OTYPER    *(unsigned int *)(GPIOF_BASE+0x04)
#define GPIOF_ODR       *(unsigned int *)(GPIOF_BASE+0x14)




#define RCC_AHB1ENR     *(unsigned int *)(RCC_BASE+0x30)