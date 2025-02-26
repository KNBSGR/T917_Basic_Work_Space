/******************************************************************************
 * Copyright (C) 2024 EternalChip, Inc.(Gmbh) or its affiliates.
 * 
 * All Rights Reserved.
 * 
 * @file T917_BSP_Key.h
 * 
 * @par 
 * 			- T917_BSP_Key.h
 *
 * 			- stdio.h
 * 			- stdint.h
 * 
 * @author T917_Ben
 * 
 * @brief Provide the HAL APIs of Key and corresponding opetions.
 * 
 * Processing flow:
 * 
 * call directly.
 * 
 * @version V1.0 2025-2-26
 *
 * @note 1 tab == 4 spaces!
 * 
 *****************************************************************************/
 
 #ifndef __T917_BSP_KEY_H__
 #define __T917_BSP_KEY_H__
 
/***************************** Includes_Begin *******************************/

#include "T917_BSP_Key.h"



/****************************** Includes_End ********************************/

/***************************** Defines_Begin *******************************/
#define OS_SUPPORTING 

/*  º¯Êý·µ»Ø×´Ì¬Ã¶¾Ù                    */
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

/****************************** Defines_End ********************************/


/***************************** Declaring_Begin *****************************/



/****************************** Declaring_End ******************************/
 
 #endif /*end of #ifndef */
 