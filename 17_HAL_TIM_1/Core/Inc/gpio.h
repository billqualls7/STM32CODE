/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define LED_G_Toggle HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin)
#define LED_R_Toggle HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin)
#define LED_B_Toggle HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin)

#define LED_G_OFF HAL_GPIO_WritePin(GPIOF, LED_G_Pin, GPIO_PIN_SET)
#define LED_R_OFF HAL_GPIO_WritePin(GPIOF, LED_R_Pin, GPIO_PIN_SET)
#define LED_B_OFF HAL_GPIO_WritePin(GPIOF, LED_B_Pin, GPIO_PIN_SET)

#define LED_G_ON HAL_GPIO_WritePin(GPIOF, LED_G_Pin, GPIO_PIN_RESET)
#define LED_R_ON HAL_GPIO_WritePin(GPIOF, LED_R_Pin, GPIO_PIN_RESET)
#define LED_B_ON HAL_GPIO_WritePin(GPIOF, LED_B_Pin, GPIO_PIN_RESET)


#define LED_ALL_OFF HAL_GPIO_WritePin(GPIOF, LED_R_Pin|LED_G_Pin|LED_B_Pin, GPIO_PIN_SET)

#define KEY_ON 1
#define KEY_OFF 0

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

