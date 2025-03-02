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
 * @attention ������ν���
 ******************************************************************************
 * @note 
 *       1 tab size == 4 spaces!
 *       Encoding use Chinese GB2312(Simplified)!
 *       Comments use / * * /
 *****************************************************************************/


/***************************** Includes_Begin *******************************/

/****************************** My_Header_File ****************************/
#include "T917_BSP_Key.h"

/****************************** Includes_End ********************************/


/***************************** Defines_Begin *******************************/

/****************** Thread_Func_Begin *******************/
osThreadId_t Key_TaskHandle;
const osThreadAttr_t Key_Task_attributes = {
  .name = "Key_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/******************* Thread_Func_END ********************/

/****************** Queue_Handler_Begin *****************/
QueueHandle_t key_queue;
/******************* Queue_Handler_END ******************/

/****************************** Defines_End ********************************/

/**
 * @brief Key scan operation
 * 
 * Steps:
 *  	1. �жϰ�����PA0)�ĵ�ƽ�Ƿ�Ϊ�ͣ����жϰ����Ƿ񱻰���.
 * 	 	2. ������������£����޸�*key_value��ֵ��������KEY_OK.
 *  	3. �������ʼ��δ�����򷵻س�ʱ.
 *  
 * @param[in] key_value : Pointer to the target of handler.
 * 
 * @return key_status_t : Status of the function.
 * 
 * */
key_status_t key_scan(key_press_status_t * key_value)
{
	uint32_t counter = 0;
    key_press_status_t key_status_value = KEY_NOT_PRESSED;
    
    while (counter < 1000)
	{
        if(HAL_GPIO_ReadPin(Key_GPIO_Port, Key_Pin) == GPIO_PIN_RESET)
        {
            key_status_value = KEY_PRESSED;
            *key_value = key_status_value;
            return KEY_OK;
        }
        counter++;
    }/*end for while(counter < 1000)*/
    *key_value = key_status_value;
    
    return KEY_ERRORTIMEOUT;
}

/**
 * @brief key thread function.
 * 
 * Steps:
 * 		1.��ȡkey_queue����ֵ����ӡ����ж��߳��Ƿ񴴽��ɹ���
 * 		2.����key_scan�����жϼ���״̬��
 * 		3.���ݼ���״̬���з��Ͷ��в�����
 *  
 * @param[in] void *argument        : Pointer to the target of handler.
 * 
 * @return voidn.
 * 
 * */
void Key_Task_F(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	key_status_t  ket_ret          =          KEY_OK;
	key_press_status_t key_statues = KEY_NOT_PRESSED;
	key_queue = xQueueCreate( 10, sizeof( uint32_t ) );
	uint32_t counter_tick = 0;
  /* Infinite loop */
	
	if (NULL == key_queue )
	{
      printf("key_queue created failed \r\n");
	} 
	else
	{
      printf("key_queue created successfully \r\n");
	}
	
  for(;;)
  {                                                       
//		printf("This is a TEST!\r\n");
		counter_tick++;
	  
		ket_ret = key_scan(&key_statues);
	  
		if(KEY_OK == ket_ret)
		{
			if(KEY_PRESSED == key_statues)
			{
				printf("KEY_PRESSED!\r\n");
				if ( pdTRUE == xQueueSendToFront(key_queue,&counter_tick,0))
				{
					printf("send successfully\r\n");
				}
			}
		}
		if(KEY_OK != ket_ret)
		{
			printf("KEY_NOT_PRESSED!\r\n");
		}
    osDelay(100);
  }
  /* USER CODE END StartDefaultTask */
}





