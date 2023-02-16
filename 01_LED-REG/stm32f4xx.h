/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-11-16 13:15:44
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-11-16 14:59:18
 * @FilePath: \LED-REG\stm32f4xx.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
 
 
 
/* 用来存放寄存器映射相关代码 */

#define RCC_AHB1ENG *(unsigned int *)( 0x40023800+0x30)
#define GPIOF_MODER *(unsigned int *)(0x40021400+0x00)
#define GPIOF_ODR *(unsigned int *)(0x40021400+0x14)