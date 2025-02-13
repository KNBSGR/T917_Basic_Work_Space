#include "Key.h"

uint8_t Key_Scan(void)
{
	uint8_t LED_State = 0;/*LED��״̬ 0ΪϨ��1Ϊ����*/
	uint8_t Key_State = 0;/*������LED״̬��0ΪϨ��Ͽ���1Ϊ��������*/
	if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == GPIO_PIN_SET && LED_State == 0)/*�������û�а�����LED��Ϩ��*/
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