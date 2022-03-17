/**
	******************************************************************************
	* @file    Project/GPIO/GPIO_EXIT/stm32f4xx_it.h
	* @author  Geunhyeok Lee
	* @version V0.0.1
	* @date    06-February-2022
	* @brief   This file contains the headers of the interrupt handlers.
	******************************************************************************
	*/
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "circular_buffer.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define RX_BUF_LEN	32
		
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void USART2_IRQHandler(void);
void ADC_IRQHandler(void);

extern CircularBuffer rx_circular_buffer;
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */

/******************************** END OF FILE *********************************/