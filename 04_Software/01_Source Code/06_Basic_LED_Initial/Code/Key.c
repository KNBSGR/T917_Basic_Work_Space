#include "Key.h"

uint8_t Key_Scan(void)
{
	uint8_t LED_State = 0;/*LED灯状态 0为熄灭，1为点亮*/
	uint8_t Key_State = 0;/*按键与LED状态，0为熄灭断开，1为点亮吸合*/
	if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == GPIO_PIN_SET && LED_State == 0)/*如果按键没有按下且LED灯熄灭*/
	{
		HAL_Delay(20);
		LED_State = 1;
		Key_State = 1;
		return Key_State;
	}
	else if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == GPIO_PIN_RESET && LED_State == 1)
	{
		HAL_Delay(20);
		LED_State = 0;
		Key_State = 0;
		return Key_State;
	}
	else
	{
		/*do nothing ...*/
	}
}	