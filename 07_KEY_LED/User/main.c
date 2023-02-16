/*
 * @Author: Wuyao 1955416359@qq.com
 * @Date: 2022-12-08 16:21:28
 * @LastEditors: Wuyao 1955416359@qq.com
 * @LastEditTime: 2022-12-09 14:25:03
 * @FilePath: \STM32CODE\06_FWLIB-TEMPALTE\User\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include"stm32f4xx.h"
#include"bsp_led.h"
#include"bsp_key.h"

int FLAG=1;
int main()
{
  
  KEY_GPIO_Config();
  LED_GPIO_Config();
  
  
  while (1)
  {
    if (KEY_Scan(GPIOC,GPIO_Pin_13)==KEY_ON)
    {
      FLAG=-FLAG;
     
    }
    if (FLAG>0)
    {
       GPIO_SetBits(GPIOF,GPIO_Pin_6);
    }
    else  GPIO_ResetBits(GPIOF,GPIO_Pin_6);
    
  }
 
  
}

