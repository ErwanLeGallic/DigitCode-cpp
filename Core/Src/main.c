/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "stm32l1xx_it.h"
#include <string.h>


#include "main.hpp"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
int __io_putchar(int ch) {
	ITM_SendChar(ch);
	return ch;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


int flag_btn=0;
int btn_trig=0;
/*
uint32_t pos = 0;

char root_code[4];
char user_code[4];
char final_code[4];


void code_bon(uint32_t MyDelay){
	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(4,'C');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(3,'C');
	MAX7219_DisplayChar(4,'O');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2,'C');
	MAX7219_DisplayChar(3,'O');
	MAX7219_DisplayChar(4,'D');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'C');
	MAX7219_DisplayChar(2,'O');
	MAX7219_DisplayChar(3,'D');
	MAX7219_DisplayChar(4,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'O');
	MAX7219_DisplayChar(2,'D');
	MAX7219_DisplayChar(3,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'D');
	MAX7219_DisplayChar(2,'E');
	MAX7219_DisplayChar(4,'B');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'E');
	MAX7219_DisplayChar(3,'B');
	MAX7219_DisplayChar(4,'O');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2,'B');
	MAX7219_DisplayChar(3,'O');
	MAX7219_DisplayChar(4,'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'B');
	MAX7219_DisplayChar(2,'O');
	MAX7219_DisplayChar(3,'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'O');
	MAX7219_DisplayChar(2,'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'N');
	HAL_Delay(MyDelay);
	MAX7219_Clear();

}

void aff_message(const char* mot, uint32_t MyDelay) {
    size_t len_mot = strlen(mot);
    for (size_t i = 0; i < len_mot; i++) {
        char lettre = mot[i];
        if (lettre == ' ') {
            MAX7219_Clear();
            HAL_Delay(MyDelay);
        } else {
            MAX7219_Clear();
            MAX7219_DisplayChar(4, lettre); // Utilisation d'une position fixe ici
            HAL_Delay(MyDelay);
        }
    }
}
*/

/*
void ask_code(uint32_t MyDelay){
	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(4,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(3,'E');
	MAX7219_DisplayChar(4,'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2,'E');
	MAX7219_DisplayChar(3,'N');
	MAX7219_DisplayChar(4,'T');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'E');
	MAX7219_DisplayChar(2,'N');
	MAX7219_DisplayChar(3,'T');
	MAX7219_DisplayChar(4,'R');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'N');
	MAX7219_DisplayChar(2,'T');
	MAX7219_DisplayChar(3,'R');
	MAX7219_DisplayChar(4,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'T');
	MAX7219_DisplayChar(2,'R');
	MAX7219_DisplayChar(3,'E');
	MAX7219_DisplayChar(4,'R');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'R');
	MAX7219_DisplayChar(2,'E');
	MAX7219_DisplayChar(3,'R');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'E');
	MAX7219_DisplayChar(2,'R');
	MAX7219_DisplayChar(4,'C');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'R');
	MAX7219_DisplayChar(3,'C');
	MAX7219_DisplayChar(4,'O');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2,'C');
	MAX7219_DisplayChar(3,'O');
	MAX7219_DisplayChar(4,'D');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'C');
	MAX7219_DisplayChar(2,'O');
	MAX7219_DisplayChar(3,'D');
	MAX7219_DisplayChar(4,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'O');
	MAX7219_DisplayChar(2,'D');
	MAX7219_DisplayChar(3,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'D');
	MAX7219_DisplayChar(2,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1,'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	HAL_Delay(MyDelay);

}
void affiche_1(int pos){
	MAX7219_DisplayChar(pos,'1');
}

void affiche_2(int pos){
	MAX7219_DisplayChar(pos,'2');
}

void affiche_3(int pos){
	MAX7219_DisplayChar(pos,'3');
}

void affiche_4(int pos){
	MAX7219_DisplayChar(pos,'4');
}

char* code() {
    HAL_Delay(300);
    while (pos < 4) {
        HAL_Delay(100);
        if (btn_trig == 1) {
            if (flag_btn == 1) {
                pos++;
                affiche_1(pos);
                user_code[pos - 1] = '1';
                btn_trig = 0;
            } else if (flag_btn == 2) {
                pos++;
                affiche_2(pos);
                user_code[pos - 1] = '2';
                btn_trig = 0;
            } else if (flag_btn == 3) {
                pos++;
                affiche_3(pos);
                user_code[pos - 1] = '3';
                btn_trig = 0;
            } else if (flag_btn == 4) {
                pos++;
                affiche_4(pos);
                user_code[pos - 1] = '4';
                btn_trig = 0;
            }
            btn_trig = 0;
            HAL_Delay(250);
        }
    }
    for (uint32_t a = 0; a < 4; a++) final_code[a] = user_code[a];
    pos=0;
    return final_code;
}
void code_faux(){
	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(1,'N');
	MAX7219_DisplayChar(2,'O');
	MAX7219_DisplayChar(3,'N');
}

*/

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  printf("Init system...\r\n");
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {






	  //code_ok(500);
	  //ask_code(300);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  main_cpp();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLL_DIV3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : btn4_Pin btn3_Pin */
  GPIO_InitStruct.Pin = btn4_Pin|btn3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI_CS_Pin */
  GPIO_InitStruct.Pin = SPI_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : btn1_Pin btn2_Pin */
  GPIO_InitStruct.Pin = btn1_Pin|btn2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == btn1_Pin) {
	  flag_btn=1;
	  btn_trig=1;
  }
  else if(GPIO_Pin == btn2_Pin) {
	  flag_btn=2;
	  btn_trig=1;

  }
  else if(GPIO_Pin == btn3_Pin) {
	  flag_btn=3;
	  btn_trig=1;

  }
  else if(GPIO_Pin == btn4_Pin) {
	  flag_btn=4;
	  btn_trig=1;
  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
