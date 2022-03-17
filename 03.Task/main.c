#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#define EXAMPLE_9

void BoardInit(void);

#ifdef EXAMPLE_1
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTask1(void *pvParameters)
{
	const char *pcTaskName = "Task 1 is running\r\n";
	volatile uint32_t ul; 
	
	for(;;)
	{
		USART_Puts(pcTaskName);
		for(ul = 0; ul < 0x004FFFFF; ul++);
	}
}

void vTask2(void *pvParameters)
{
	const char *pcTaskName = "Task 2 is running\r\n";
	volatile uint32_t ul; 
	
	for(;;)
	{
		USART_Puts(pcTaskName);
		for(ul = 0; ul < 0x004FFFFF; ul++);
	}
}
#endif

#ifdef EXAMPLE_2
static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";

void vTaskFunction(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 1, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTaskFunction(void *pvParameters)
{
	char *pcTaskName;
	volatile uint32_t ul;
	
	pcTaskName = (char *)pvParameters;
	
	for(;;)
	{
		USART_Puts(pcTaskName);
		for(ul = 0; ul < 0x004FFFFF; ul++);
	}
}
#endif

#ifdef EXAMPLE_3
static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";

void vTaskFunction(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 2, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTaskFunction(void *pvParameters)
{
	char *pcTaskName;
	volatile uint32_t ul;
	
	pcTaskName = (char *)pvParameters;
	
	for(;;)
	{
		USART_Puts(pcTaskName);
		for(ul = 0; ul < 0x002FFFFF; ul++);
	}
}
#endif

#ifdef EXAMPLE_4
static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";

void vTaskFunction(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 2, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTaskFunction(void *pvParameters)
{
	char *pcTaskName;
	const TickType_t xDelay250ms = pdMS_TO_TICKS(1000);
	pcTaskName = (char *)pvParameters;
	
	for(;;)
	{
		USART_Puts(pcTaskName);
		vTaskDelay(xDelay250ms);
	}
}
#endif

#ifdef EXAMPLE_5
static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";

void vTaskFunction(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 2, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTaskFunction(void *pvParameters)
{
	char *pcTaskName;
	TickType_t xLastWakeTime;
	pcTaskName = (char *)pvParameters;
	
	xLastWakeTime = xTaskGetTickCount();
	
	for(;;)
	{
		USART_Puts(pcTaskName);
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(250));
	}
}
#endif

#ifdef EXAMPLE_6
static const char *pcTextForTask1 = "Continuous task 1 is running\r\n";
static const char *pcTextForTask2 = "Continuous task 2 is running\r\n";

void vContinuousProcessingTask(void *pvParameters);
void vPeriodicTask(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vContinuousProcessingTask, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vContinuousProcessingTask, "Task 2", 1000, (void*)pcTextForTask2, 1, NULL);
	xTaskCreate(vPeriodicTask, "Task 3", 1000, (void*)pcTextForTask2, 2, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vContinuousProcessingTask(void *pvParameters)
{
	char *pcTaskName;
	pcTaskName = (char *)pvParameters;
		
	for(;;)
	{
		USART_Puts(pcTaskName);
	}
}

void vPeriodicTask(void *pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xDealy100ms = pdMS_TO_TICKS(100);
	
	xLastWakeTime = xTaskGetTickCount();
	
	for(;;)
	{
		USART_Puts("Periodic task is running\r\n");
		vTaskDelayUntil(&xLastWakeTime, xDealy100ms);
	}
}
#endif

#ifdef EXAMPLE_7
volatile uint32_t ulIdleCycleCount = 0UL;

static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";

void vTaskFunction(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 2, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vApplicationIdleHook(void)
{
	ulIdleCycleCount++;
}

void vTaskFunction(void *pvParameters)
{
	char *pcTaskName;
	const TickType_t xDelay250ms = pdMS_TO_TICKS(250);
	pcTaskName = (char *)pvParameters;
	
	for(;;)
	{
		_printf("%sulIdleCycleCount = %d\r\n", pcTaskName, ulIdleCycleCount);
		vTaskDelay(xDelay250ms);
	}
}
#endif

#ifdef EXAMPLE_8
TaskHandle_t xTask2Handle = NULL;
	
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 2, NULL);
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, &xTask2Handle);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTask1(void *pvParameters)
{
	UBaseType_t uxPriority;
	uxPriority = uxTaskPriorityGet(NULL);
	

	for(;;)
	{
		_printf("1 \t %d \r\n",xTaskGetTickCount());
		//USART_Puts("Task 1 is running\r\n");
		//USART_Puts("About to raise the Task2 priority\r\n");
		vTaskPrioritySet(xTask2Handle, (uxPriority + 1));
	}
}
	
void vTask2(void *pvParameters)
{
	UBaseType_t uxPriority;
	uxPriority = uxTaskPriorityGet( NULL );
 
	for( ;; )
	{
		_printf("2 \t %d \r\n",xTaskGetTickCount());
		//USART_Puts("Task 2 is running\r\n");
		//USART_Puts("About to lower the Task 2 priority\r\n" );
		vTaskPrioritySet( NULL, ( uxPriority - 2 ) );
	}
}
#endif

#ifdef EXAMPLE_9
TaskHandle_t xTask2Handle = NULL;
	
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main()
{
	SystemInit();
	BoardInit();
	
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	for(;;);
	
	return 0;
}

void vTask1(void *pvParameters)
{
	const TickType_t xDelay100ms = pdMS_TO_TICKS(10UL);
	uint32_t ul; 
	
	for(;;)
	{
		USART_Puts("Task 1 is running\r\n");
		xTaskCreate(vTask2, "Task 2", 1000, NULL, 2, &xTask2Handle);
		vTaskDelay(xDelay100ms);
	}
}
	
void vTask2(void *pvParameters)
{
	_printf("2 \t %d \r\n",xTaskGetTickCount());
	USART_Puts("Task 2 is running and about to delete itself\r\n");
	vTaskDelete(xTask2Handle);
}
#endif

void BoardInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x060;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_Init(&NVIC_InitStructure);
	
	return;
}
/******************************** END OF FILE *********************************/