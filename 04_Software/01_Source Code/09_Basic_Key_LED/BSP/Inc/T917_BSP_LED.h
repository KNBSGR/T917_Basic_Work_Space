/******************************************************************************
 * Copyright (C) 2025 "CompanyName" Inc.(Gmbh) or its affiliates.
 * All Rights Reserved.
 ******************************************************************************
 * @file "FileName"
 * @brief Provide the HAL APIs of "LED" and corresponding opetions.
 * @par 
 *     - T917_BSP_Key.h 
 *     - stdio.h
 *     - stdint.h
 * @author KNBSGR
 ******************************************************************************
 * @version V1.01.01.20240227_Alpha
 * @attention 代码初次建立
 ******************************************************************************
 * @note 
 *       1 tab == 4 spaces!
 *       Encoding use Chinese GB2312(Simplified)!
 *       Comments use / * * /
 *****************************************************************************/
 
 #ifndef __T917_BSP_LED_H__
 #define __T917_BSP_LED_H__
 
/***************************** Includes_Begin *******************************/

/****************************** My_Header_File ****************************/
#include "T917_BSP_LED.h"

/************************** Compiler_Header_File **************************/
#include <stdint.h> 
#include <stdio.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#include "cmsis_os.h"
#include "queue.h"

/****************************** Includes_End ********************************/


/***************************** Defines_Begin *******************************/

/***************************** Typedef Enum ********************************/
typedef enum
{ 
	LED_OK                = 0,         /* Operation completed successfully.  */
	LED_ERROR             = 1,         /* Run-time error without case matched*/
	LED_ERRORTIMEOUT      = 2,         /* Operation failed with timeout      */
	LED_ERRORRESOURCE     = 3,         /* Resource not available.            */
	LED_ERRORPARAMETER    = 4,         /* Parameter error.                   */
	LED_ERRORNOMEMORY     = 5,         /* Out of memory.                     */
	LED_ERRORISR          = 6,         /* Not allowed in ISR context         */
	LED_RESERVED          = 0x7FFFFFFF /* Reserved                           */
} 	led_status_t;

typedef enum
{
	LED_OFF          	= 0,         /* Operation completed successfully.  */
	LED_ON      		= 1,         /* Run-time error without case matched*/
	LED_TOGGLE      	= 2,         /* Run-time error without case matched*/
} 	led_operation_t;

/****************** Thread_Func_Begin *******************/
extern osThreadId_t              led_TaskHandle;
extern const osThreadAttr_t led_Task_attributes;
/******************* Thread_Func_END ********************/

/****************** Queue_Handler_Begin *****************/
extern QueueHandle_t led_queue;
/******************* Queue_Handler_END ******************/

/****************************** Defines_End ********************************/


/***************************** Declaring_Begin *****************************/

led_status_t  	led_on_off     (led_operation_t led_operation);
void         	led_task_func                 (void *argument);

/****************************** Declaring_End ******************************/
 
 #endif /*end of #ifndef __T917_BSP_LED_H__ */
 
