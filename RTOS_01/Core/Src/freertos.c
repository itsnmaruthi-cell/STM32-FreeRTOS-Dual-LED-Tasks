/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern volatile uint32_t* GPIOA_BSRR;//this is already in main.c
//we are just making a ocnnection between main.c and freertos.c

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void LED_Task1(void* arguments){
	while(1){
		*GPIOA_BSRR=(1U<<5);
		vTaskDelay(pdMS_TO_TICKS(500));
		*GPIOA_BSRR=(1U<<(5+16));
		vTaskDelay(pdMS_TO_TICKS(500));
		//total cycle is 1000ms
	}
}
void LED_Task2(void* arguments){
	while(1){
			*GPIOA_BSRR=(1U<<6);
			vTaskDelay(pdMS_TO_TICKS(1000));
			*GPIOA_BSRR=(1U<<(6+16));
			vTaskDelay(pdMS_TO_TICKS(1000));
			//total cycle is 2000ms
	}
}

/* USER CODE END Application */

