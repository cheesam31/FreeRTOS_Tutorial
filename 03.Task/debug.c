/**
******************************************************************************
* @file    Project/STM32F407-DISC1_TEST/debug.c 
* @author  Geunhyeok Lee
* @version V0.0.1
* @date    05-January-2021
* @brief   Main program body
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "debug.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

static char _printf_buffer[256] = {0,};

void USART_Puts(const char *str)
{
	while(*str)
	{
		while(!(USART2->SR & USART_FLAG_TXE));
		USART_SendData(USART2, *str++);
		while(!(USART2->SR & USART_FLAG_TXE));
	}
	return;
}

#pragma __printf_args
void _printf(char *format, ...)
{
	va_list args;
	_printf_buffer[0] = 0;
	
	va_start(args, format);
	vsnprintf(_printf_buffer, 255, format, args);
	va_end(args);
	
	USART_Puts(_printf_buffer);
	
	return;
}