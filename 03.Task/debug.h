/**
******************************************************************************
* @file    Project/STM32F407-DISC1_TEST/debug.h
* @author  Geunhyeok Lee
* @version V0.0.1
* @date    05-January-2021
* @brief   Main program body
******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEBUG_H
#define __DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void USART_Puts(const char *str);
void _printf(char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* __DEBUG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/