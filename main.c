/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint32_t lot1;
uint32_t lot2;
uint8_t lot3;
uint8_t lot4;
uint32_t lot5;
uint32_t lot6;
uint8_t lot7;
uint8_t lot8;

uint8_t cont = 8;

uint8_t a = 1;
uint8_t b = 1;
uint8_t c = 1;
uint8_t d = 1;
uint8_t e = 1;
uint8_t f = 1;
uint8_t g = 1;
uint8_t h = 1;

#define TXBUFFERSIZE 4
#define RXBUFFERSIZE 4

uint8_t aTxBuffer[TXBUFFERSIZE];
uint8_t aRxBuffer[RXBUFFERSIZE];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void DISPLAY(int cont){
switch (cont){
  case 0:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
	  break;
  case 1:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
	  break;
  case 2:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
	  break;
  case 3:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
	  break;
  case 4:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
	  break;
  case 5:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
	  break;
  case 6:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
	  break;
  case 7:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
	  break;
  case 8:
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
	  break;
  }
}
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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 1);
  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 0);

  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, 1);
  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, 0);

  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, 1);
  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, 0);

  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, 1);
  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, 0);

  if(HAL_I2C_EnableListen_IT(&hi2c1) != HAL_OK){
	  Error_Handler();
  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

//************************************PUERTOS FATIMA*************************
	  if(lot1){

	  	while(a < 1){
	  		cont++;
	  		a = 1;
	  	}
	  }else{

	  	while(a > 0){
	  		cont--;
	  		a = 0;
	  	}
	  }

	  if(lot2){

	  	while(b < 1){
	  		cont++;
	  		b = 1;
	  	}
	  }else{

	  	while(b > 0){
	  		cont--;
	  		b = 0;
	  	}
	  }

	  if(lot3){

	  	while(c < 1){
	  		cont++;
	  		c = 1;
	  	}
	  }else{

	  	while(c > 0){
	  		cont--;
	  		c = 0;
	  	}
	  }

	  if(lot4){

	  	while(d < 1){
	  		cont++;
	  		d = 1;
	  	}
	  }else{

	  	while(d > 0){
	  		cont--;
	  		d = 0;
	  	}
	  }
//********************************PUERTOS FATIMA*****************************

	  lot5 = HAL_GPIO_ReadPin(S5_GPIO_Port, S5_Pin);
	  if(lot5){
		  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 1);
		  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 0);

	  	while(e < 1){
	  		cont++;
	  		e = 1;
	  		DISPLAY(cont);

	  	}
	  }else{
		  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 0);
		  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 1);

	  	while(e > 0){
	  		cont--;
	  		e = 0;
	  		DISPLAY(cont);
	  	}
	  }

	  lot6 = HAL_GPIO_ReadPin(S6_GPIO_Port, S6_Pin);
	  if(lot6){
		  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, 1);
		  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, 0);
	  	while(f < 1){
	  		cont++;
	  		f = 1;
	  		DISPLAY(cont);
	  	}
	  }else{
		  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, 0);
		  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, 1);
	  	while(f > 0){
	  		cont--;
	  		f = 0;
	  		DISPLAY(cont);
	  	}
	  }

	  lot7 = HAL_GPIO_ReadPin(S7_GPIO_Port, S7_Pin);
	  if(lot7){
		  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, 1);
		  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, 0);
	  	while(g < 1){
	  		cont++;
	  		g = 1;
	  		DISPLAY(cont);
	  	}
	  }else{
		  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, 0);
		  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, 1);
	  	while(g > 0){
	  		cont--;
	  		g = 0;
	  		DISPLAY(cont);
	  	}
	  }

	  lot8 = HAL_GPIO_ReadPin(S8_GPIO_Port, S8_Pin);
	  if(lot8){
		  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, 1);
		  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, 0);
	  	while(h < 1){
	  		cont++;
	  		h = 1;
	  		DISPLAY(cont);
	  	}
	  }else{
		  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, 0);
		  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, 1);
	  	while(h > 0){
	  		cont--;
	  		h = 0;
	  		DISPLAY(cont);
	  	}
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 170;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

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
  HAL_GPIO_WritePin(GPIOC, R1_Pin|C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|A_Pin|B_Pin|G_Pin
                          |R3_Pin|G3_Pin|G1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, R2_Pin|G2_Pin|D_Pin|R4_Pin
                          |G4_Pin|E_Pin|F_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : S5_Pin S6_Pin S7_Pin S8_Pin */
  GPIO_InitStruct.Pin = S5_Pin|S6_Pin|S7_Pin|S8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : R1_Pin C_Pin */
  GPIO_InitStruct.Pin = R1_Pin|C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin A_Pin B_Pin G_Pin
                           R3_Pin G3_Pin G1_Pin */
  GPIO_InitStruct.Pin = LD2_Pin|A_Pin|B_Pin|G_Pin
                          |R3_Pin|G3_Pin|G1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : R2_Pin G2_Pin D_Pin R4_Pin
                           G4_Pin E_Pin F_Pin */
  GPIO_InitStruct.Pin = R2_Pin|G2_Pin|D_Pin|R4_Pin
                          |G4_Pin|E_Pin|F_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c)
{
  HAL_I2C_EnableListen_IT(&hi2c1);

}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *I2cHandle)
{
  /* Prevent unused argument(s) compilation warning */
  aTxBuffer[0] = lot5;
  aTxBuffer[1] = lot6;
  aTxBuffer[2] = lot7;
  aTxBuffer[3] = lot8;
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *I2cHandle)
{
  /* Prevent unused argument(s) compilation warning */
  lot1 = aRxBuffer[0];
  lot2 = aRxBuffer[1];
  lot3 = aRxBuffer[2];
  lot4 = aRxBuffer[3];

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_SlaveRxCpltCallback could be implemented in the user file
   */
}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
  /* Prevent unused argument(s) compilation warning */
  if(TransferDirection == I2C_DIRECTION_TRANSMIT){
	  if(HAL_I2C_Slave_Seq_Receive_IT(&hi2c1, (uint8_t*) aRxBuffer, RXBUFFERSIZE, I2C_FIRST_AND_LAST_FRAME) != HAL_OK){
		  Error_Handler();
	  }
  }else if (TransferDirection == I2C_DIRECTION_RECEIVE) {

	  aTxBuffer[0] = lot5;
	  aTxBuffer[1] = lot6;
	  aTxBuffer[2] = lot7;
	  aTxBuffer[3] = lot8;

	  if(HAL_I2C_Slave_Seq_Transmit_IT(&hi2c1, (uint8_t*) aTxBuffer, TXBUFFERSIZE, I2C_FIRST_AND_LAST_FRAME) != HAL_OK){
		  Error_Handler();
	  }
  }

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_AddrCallback() could be implemented in the user file
   */
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *I2cHandle)
{
  /* Prevent unused argument(s) compilation warning */
  if(HAL_I2C_GetError(I2cHandle) != HAL_I2C_ERROR_AF){
	  Error_Handler();


	  uint32_t error = HAL_I2C_GetError(I2cHandle);
  }

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_ErrorCallback could be implemented in the user file
   */
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
