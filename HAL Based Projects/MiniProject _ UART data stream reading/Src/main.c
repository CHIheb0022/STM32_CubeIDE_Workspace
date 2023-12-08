/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../ECUAL/HCSR04/HCSR04.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define Buffer_len 3 // Received UART message have a maximum length of 3 (when setting servo-motors speed).
#define ARR_value 65535 // TIM2 Auto Reload Register set to . (2^16)

#define FL GPIO_PIN_5 // GPIOA_PIN5 Front Light
#define BL GPIO_PIN_0 // GPIOC_PIN0 Back Light

#define MA GPIO_PIN_0 // GPIOA_PIN0 Servo-Motor A : Configured as a PWM output (Channel_1)
#define MB GPIO_PIN_1 // GPIOA_PIN1 Servo-Motor B : Configured as a PWM output (Channel_2)

#define Turning_Speed1 60
#define Turning_Speed2 100 // Speed difference is set to 40 in order to perform a smooth turn.

#define HCSR04_SENSOR1  0 // HCSR04 ID used to instanciate the sensor using the ECUAL library.


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

uint16_t SysTicks = 0;
uint8_t RX_BUFFER[Buffer_len];
float Distance = 0.0; // Distance from barrier to the HCSR04 Sensor.
uint16_t x_speed = 0;
uint32_t x_OCC;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);

static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
//static void MX_TIM3_Init(void); // We don't need the CubeMX Initialization Function since this action is performed on the ECUAL Library.

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *); // Callback function: We are reading from UART in Interrupt mode.
uint32_t MAP(uint32_t au32_IN, uint32_t au32_INmax, uint32_t au32_OUTmax); // This is a modified version from DeepBLue Math Library (I have considered a 0 min for both input and output intervals).

void Front_Light_Toggle();
void Back_Light_Toggle();
void Turn_Left();
void Turn_Right();
void Stop();
float Range_to_obstacle(uint8_t); // Consider transforming this function on a Alert function (cause with the HCSR04_Read direct reading capabilities it becomes useless).
void ServoA_Speed_Calibration(uint16_t);
void ServoB_Speed_Calibration(uint16_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


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
  MX_TIM2_Init();

  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  //MX_TIM3_Init();

  //Start the PWM mode on the channel of timer1
  HAL_TIMEx_PWMN_Start(&htim2, TIM_CHANNEL_1);

  //Start the PWM mode on the channel of timer2
  HAL_TIMEx_PWMN_Start(&htim2, TIM_CHANNEL_2);

  //Setup the trigger for the first reading from the UART.
  HAL_UART_Receive_IT(&huart2, RX_BUFFER, Buffer_len);

  //Initializing the HCSR04 with the ID HCSR04_SENSOR1 attached to Timer 2.
  HCSR04_Init(HCSR04_SENSOR1, &htim3); // Am using Timer 3 to capture signal events (rising, falling) for the HCSR04 sensor.

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	//Until this stage we will be using the range function to return the distance an monitoring it using the Live expression.
	Distance = Range_to_obstacle(HCSR04_SENSOR1);
	HAL_Delay(100);

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
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 20;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

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
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	uint16_t Speed = 0;
	x_speed = Speed;
	//Check the Cplt callback function call belongs to the UART1 instance.
	if (huart == &huart2) {
    // Commande reçue, effectuez des actions en fonction de RX_BUFFER[0]

    switch (RX_BUFFER[0]){

      case 'B':
    	  Front_Light_Toggle();
		  break;

      case 'C':
    	  Back_Light_Toggle();
    	  break;

      case 'D':
    	  Turn_Left();
    	  break;

      case 'E':
    	  Turn_Right();
    	  break;

      case 'F':
    	  Stop();
    	  break;

      case 'G':
    	 //Dispaly the distance from the obstacle on an LCD. using the Range_to_obstacle() function
    	  break;

      case 'J':

    	Speed = (uint16_t) (RX_BUFFER[1]<<8 | RX_BUFFER[2]);
    	ServoA_Speed_Calibration(Speed);
    	break;

      case 'K':

      	Speed = (uint16_t) (RX_BUFFER[1]<<8 | RX_BUFFER[2]);
    	ServoB_Speed_Calibration(Speed);
        break;

      default :
    	  //Print a message on the LCD to mention no action is specified.
    	break;
    }

    // Réactivez la réception UART pour la prochaine commande
    HAL_UART_Receive_IT(&huart2, RX_BUFFER, Buffer_len);
  }

}

void Front_Light_Toggle(){
	HAL_GPIO_TogglePin(GPIOA,FL);
}

void Back_Light_Toggle(){
	HAL_GPIO_TogglePin(GPIOC,BL);
}

void Stop(){
	HAL_GPIO_WritePin(GPIOA, MA, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MB, GPIO_PIN_RESET);
}

// Code to calibrate the speed of Servo A based on the received speed parameter
void ServoA_Speed_Calibration(uint16_t speed) {

	uint32_t OCC_Value = 0;
    // Use the received speed value to set the PWM duty cycle or pulse width
    // on the pin controlling Servo A (PB1 in this example)
    // Note: You may need to use a PWM library or HAL functions for precise control

	OCC_Value = MAP((uint32_t)speed, ARR_value, 180);
	x_OCC = OCC_Value;
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1, OCC_Value); // Channel 1 to control MA.
}

// Similar to ServoA_Speed_Calibration, adjust the logic for Servo B (PB2 in this example)
void ServoB_Speed_Calibration(uint16_t speed) {

	uint32_t OCC_Value = 0;
    // Use the received speed value to set the PWM duty cycle or pulse width
    // on the pin controlling Servo B
	// MAp the speed with the available CCR1 range. (This step is crucial to cover the output capture/compare full range).

	OCC_Value = MAP((uint32_t)speed, ARR_value, 180);
	x_OCC = OCC_Value;
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2, OCC_Value); // Channel 1 to control MA.
}

// Servo-Motor A is attached to the left side.
// Servo-Motor B is attached to the right side.

//Turning left: SPEED_SERVO_B > SPEED_SERVO_A
void Turn_Left(){
	// Set ServoA to Turning_Speed1 and ServoB to Turning_Speed2
	ServoA_Speed_Calibration(Turning_Speed1);
	ServoB_Speed_Calibration(Turning_Speed2);
}

//Turning left: SPEED_SERVO_A > SPEED_SERVO_B
void Turn_Right(){
	// Set ServoB to Turning_Speed1 and ServoA to Turning_Speed2
	ServoB_Speed_Calibration(Turning_Speed1);
	ServoA_Speed_Calibration(Turning_Speed2);
}


float Range_to_obstacle(uint8_t au8_HCSR04_Instance){
	return HCSR04_Read(au8_HCSR04_Instance);
}

//MAP function to Scale the giving results in order to match CCR Full range.
uint32_t MAP(uint32_t au32_IN, uint32_t au32_INmax, uint32_t au32_OUTmax)
{
    return au32_IN * (au32_OUTmax/au32_INmax);
}

//Callbacks related to the ECUAL library specification
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    HCSR04_TMR_IC_ISR(htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    HCSR04_TMR_OVF_ISR(htim);
}

void SysTick_CallBack(void)
{
    SysTicks++;
    if(SysTicks == 15) // Each 15msec
    {
        HCSR04_Trigger(0);
    SysTicks = 0;
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
