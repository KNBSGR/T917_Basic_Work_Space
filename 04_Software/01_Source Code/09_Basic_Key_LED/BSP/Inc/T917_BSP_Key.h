/******************************************************************************
 * Copyright (C) 2025 "CompanyName" Inc.(Gmbh) or its affiliates.
 * All Rights Reserved.
 ******************************************************************************
 * @file "FileName"
 * @brief Provide the HAL APIs of "Key" and corresponding opetions.
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
 
 #ifndef __T917_BSP_KEY_H__
 #define __T917_BSP_KEY_H__
 
/***************************** Includes_Begin *******************************/

/****************************** My_Header_File ****************************/
#include "T917_BSP_Key.h"

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
  KEY_OK                = 0,         /* Operation completed successfully.  */
  KEY_ERROR             = 1,         /* Run-time error without case matched*/
  KEY_ERRORTIMEOUT      = 2,         /* Operation failed with timeout      */
  KEY_ERRORRESOURCE     = 3,         /* Resource not available.            */
  KEY_ERRORPARAMETER    = 4,         /* Parameter error.                   */
  KEY_ERRORNOMEMORY     = 5,         /* Out of memory.                     */
  KEY_ERRORISR          = 6,         /* Not allowed in ISR context         */
  KEY_RESERVED          = 0x7FFFFFFF /* Reserved                           */
} key_status_t;

typedef enum
{
  KEY_PRESSED           = 0,         /* Operation completed successfully.  */
  KEY_NOT_PRESSED       = 1,         /* Run-time error without case matched*/
} key_press_status_t;

/****************** Thread_Func_Begin *******************/
extern osThreadId_t Key_TaskHandle;
extern const osThreadAttr_t Key_Task_attributes;
/******************* Thread_Func_END ********************/

/****************** Queue_Handler_Begin *****************/
extern QueueHandle_t key_queue;
/******************* Queue_Handler_END ******************/

/****************************** Defines_End ********************************/


/***************************** Declaring_Begin *****************************/

key_status_t key_scan(key_press_status_t * key_value);
void Key_Task_F(void *argument);
/****************************** Declaring_End ******************************/
 
 #endif /*end of #ifndef */
 
