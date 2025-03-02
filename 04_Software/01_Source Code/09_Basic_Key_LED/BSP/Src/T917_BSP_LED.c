/******************************************************************************
 * Copyright (C) 2025 "CompanyName" Inc.(Gmbh) or its affiliates.
 * All Rights Reserved.
 ******************************************************************************
 * @file "FileName"
 * @brief Provide the HAL APIs of "LEDy" and corresponding opetions.
 * @par 
 *     - T917_BSP_LED.h 
 *     - stdio.h
 *     - stdint.h
 * @author KNBSGR
 ******************************************************************************
 * @version V1.01.01.20240302_Alpha
 * @attention 代码初次建立
 ******************************************************************************
 * @note 
 *       1 tab size == 4 spaces!
 *       Encoding use Chinese GB2312(Simplified)!
 *       Comments use / * * /
 *****************************************************************************/


/***************************** Includes_Begin *******************************/

/****************************** My_Header_File ****************************/
#include "T917_BSP_LED.h"

/****************************** Includes_End ********************************/

/***************************** Defines_Begin *******************************/

/****************** Thread_Func_Begin *******************/
osThreadId_t              led_TaskHandle;
const osThreadAttr_t led_Task_attributes = {
  .name = "led_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/******************* Thread_Func_END ********************/

/****************** Queue_Handler_Begin *****************/
QueueHandle_t led_queue;
/******************* Queue_Handler_END ******************/

/****************************** Defines_End ********************************/

/**
 * @brief LED状态控制
 * 
 * Steps:
 *  1. 判断LED控制状态.
 *  2. 执行相应状态.
 *  
 * @param[in] led_operation : Pointer to the target of handler.
 * 
 * @return led_status_t : Status of the function.
 * 
 * */
led_status_t led_on_off(led_operation_t led_operation)
{
    led_status_t ret = LED_OK;
    
    if ( LED_ON     == led_operation )
    {
        /*Make the LED ON*/
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET); 
    }
    
    if ( LED_OFF    == led_operation )
    {
        /*Make the LED OFF*/
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    }
    
    if ( LED_TOGGLE == led_operation )
    {
        /*Make the LED Toggle*/
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    }
}


/**
 * @brief LED任务
 * 
 * Steps:
 *  1. 判断LED线程是否接收到信息.
 *  2. 执行相应状态.
 *  
 * @param[in] argument : Pointer to the target of handler.
 * 
 * @return void.
 * 
 * */
void led_task_func(void *argument)
{
    
  led_status_t      led_ret          =          LED_OK;
  led_operation_t led_value          =          LED_ON;
  led_queue = xQueueCreate( 10, sizeof( led_operation_t ) );
  if (NULL == led_queue )
  {
      printf("led_queue created failed \r\n");
  } 
  else
  {
      printf("led_queue created successfully \r\n");
  }
  for(;;)
  {
//    printf("Hello led thread\r\n");
    
    if( led_queue != 0 )
	{
		// Receive a message on the created queue.  Block for 10 ticks if a
		// message is not immediately available.
		if( xQueueReceive( led_queue, &( led_value ), ( TickType_t ) 100 ) )
		{
			// pcRxedMessage now points to the struct AMessage variable posted
			// by vATask.
            printf("received led_queue value = [%d]" , led_value);
            led_on_off(led_value);
		}
	}
    
    osDelay(100);
  }
}





