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
#include "stm32l4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TRIG_Pin GPIO_PIN_0
#define TRIG_GPIO_Port GPIOC
#define IN3_Pin GPIO_PIN_1
#define IN3_GPIO_Port GPIOC
#define IN4_Pin GPIO_PIN_2
#define IN4_GPIO_Port GPIOC
#define ENB_Pin GPIO_PIN_0
#define ENB_GPIO_Port GPIOA
#define ENA_Pin GPIO_PIN_1
#define ENA_GPIO_Port GPIOA
#define BL_Pin GPIO_PIN_4
#define BL_GPIO_Port GPIOA
#define FL_Pin GPIO_PIN_5
#define FL_GPIO_Port GPIOA
#define ECHO_Pin GPIO_PIN_6
#define ECHO_GPIO_Port GPIOA
#define IN1_Pin GPIO_PIN_1
#define IN1_GPIO_Port GPIOB
#define IN2_Pin GPIO_PIN_2
#define IN2_GPIO_Port GPIOB
#define ALERT_Pin GPIO_PIN_12
#define ALERT_GPIO_Port GPIOB
#define BLE_TX_Pin GPIO_PIN_9
#define BLE_TX_GPIO_Port GPIOA
#define BLE_RX_Pin GPIO_PIN_10
#define BLE_RX_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
