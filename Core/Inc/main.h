/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define TERM_SCL_Pin GPIO_PIN_0
#define TERM_SCL_GPIO_Port GPIOC
#define TERM_SDA_Pin GPIO_PIN_1
#define TERM_SDA_GPIO_Port GPIOC
#define TERM_DIO1_Pin GPIO_PIN_2
#define TERM_DIO1_GPIO_Port GPIOC
#define RELAY_EN_Pin GPIO_PIN_3
#define RELAY_EN_GPIO_Port GPIOC
#define TERM_TX_Pin GPIO_PIN_0
#define TERM_TX_GPIO_Port GPIOA
#define TERM_RX_Pin GPIO_PIN_1
#define TERM_RX_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_2
#define VCP_TX_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_3
#define VCP_RX_GPIO_Port GPIOA
#define EH_DAC_Pin GPIO_PIN_4
#define EH_DAC_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TERM_ADC1_Pin GPIO_PIN_4
#define TERM_ADC1_GPIO_Port GPIOC
#define TERM_ADC2_Pin GPIO_PIN_5
#define TERM_ADC2_GPIO_Port GPIOC
#define EH_ADC2_Pin GPIO_PIN_0
#define EH_ADC2_GPIO_Port GPIOB
#define EH_ADC1_Pin GPIO_PIN_1
#define EH_ADC1_GPIO_Port GPIOB
#define EH_SCL_TX_Pin GPIO_PIN_10
#define EH_SCL_TX_GPIO_Port GPIOB
#define EH_SDA_RX_Pin GPIO_PIN_11
#define EH_SDA_RX_GPIO_Port GPIOB
#define USB_SUPPLY_FAULT_Pin GPIO_PIN_12
#define USB_SUPPLY_FAULT_GPIO_Port GPIOB
#define EH_SCK_Pin GPIO_PIN_13
#define EH_SCK_GPIO_Port GPIOB
#define EH_MISO_Pin GPIO_PIN_14
#define EH_MISO_GPIO_Port GPIOB
#define EH_MOSI_Pin GPIO_PIN_15
#define EH_MOSI_GPIO_Port GPIOB
#define TERM_DIO4_Pin GPIO_PIN_6
#define TERM_DIO4_GPIO_Port GPIOC
#define TERM_DIO3_Pin GPIO_PIN_8
#define TERM_DIO3_GPIO_Port GPIOC
#define TERM_DIO2_Pin GPIO_PIN_9
#define TERM_DIO2_GPIO_Port GPIOC
#define USB_SUPPLY_EN_Pin GPIO_PIN_8
#define USB_SUPPLY_EN_GPIO_Port GPIOA
#define EH_DIO1_Pin GPIO_PIN_10
#define EH_DIO1_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define TERM_SCK_Pin GPIO_PIN_10
#define TERM_SCK_GPIO_Port GPIOC
#define TERM_MISO_Pin GPIO_PIN_11
#define TERM_MISO_GPIO_Port GPIOC
#define TERM_MOSI_Pin GPIO_PIN_12
#define TERM_MOSI_GPIO_Port GPIOC
#define TERM_CS_Pin GPIO_PIN_2
#define TERM_CS_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define EH_DIO3_Pin GPIO_PIN_4
#define EH_DIO3_GPIO_Port GPIOB
#define EH_DIO2_Pin GPIO_PIN_5
#define EH_DIO2_GPIO_Port GPIOB
#define PERIF_SCL_Pin GPIO_PIN_8
#define PERIF_SCL_GPIO_Port GPIOB
#define PERIF_SDA_Pin GPIO_PIN_9
#define PERIF_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
