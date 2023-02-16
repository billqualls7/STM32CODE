/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY2_EXTI_Pin GPIO_PIN_13
#define KEY2_EXTI_GPIO_Port GPIOC
#define KEY2_EXTI_EXTI_IRQn EXTI15_10_IRQn
#define LED_R_Pin GPIO_PIN_6
#define LED_R_GPIO_Port GPIOF
#define LED_G_Pin GPIO_PIN_7
#define LED_G_GPIO_Port GPIOF
#define LED_B_Pin GPIO_PIN_8
#define LED_B_GPIO_Port GPIOF
#define KEY1_EXTI_Pin GPIO_PIN_0
#define KEY1_EXTI_GPIO_Port GPIOA
#define KEY1_EXTI_EXTI_IRQn EXTI0_IRQn

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

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
