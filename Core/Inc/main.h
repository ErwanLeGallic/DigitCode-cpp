/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32l1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern SPI_HandleTypeDef hspi1;

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
extern int flag_btn; // Déclaration externe, pas d'initialisation
extern int btn_trig;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define SPI_SCK_Pin GPIO_PIN_5
#define SPI_SCK_GPIO_Port GPIOA
#define SPI_MISO_Pin GPIO_PIN_6
#define SPI_MISO_GPIO_Port GPIOA
#define SPI_MOSI_Pin GPIO_PIN_7
#define SPI_MOSI_GPIO_Port GPIOA
#define btn4_Pin GPIO_PIN_5
#define btn4_GPIO_Port GPIOC
#define btn4_EXTI_IRQn EXTI9_5_IRQn
#define btn3_Pin GPIO_PIN_6
#define btn3_GPIO_Port GPIOC
#define btn3_EXTI_IRQn EXTI9_5_IRQn
#define SPI_CS_Pin GPIO_PIN_8
#define SPI_CS_GPIO_Port GPIOA
#define btn1_Pin GPIO_PIN_11
#define btn1_GPIO_Port GPIOA
#define btn1_EXTI_IRQn EXTI15_10_IRQn
#define btn2_Pin GPIO_PIN_12
#define btn2_GPIO_Port GPIOA
#define btn2_EXTI_IRQn EXTI15_10_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/*
void aff_message(char mot, uint32_t MyDelay);
void ask_code(uint32_t MyDelay);
void code_bon(uint32_t MyDelay);
void code_faux();
void affiche_1(uint32_t pos);
void affiche_2(uint32_t pos);
void affiche_3(uint32_t pos);
void affiche_4(uint32_t pos);
char* code();
*/
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif
#include <main.hpp>

#endif /* __MAIN_H */
