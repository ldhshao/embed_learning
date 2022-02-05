#include "key.h"
#include "../rcc/rcc.h"
#include "../led/led.h"

void init_key()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY_UP_PORT_RCC,ENABLE);
	GPIO_InitStructure.GPIO_Pin=KEY_UP_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_UP_Port,&GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(KEY_PORT_RCC,ENABLE);
	GPIO_InitStructure.GPIO_Pin=(KEY_LEFT_Pin|KEY_DOWN_Pin|KEY_RIGHT_Pin);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_UP_Port,&GPIO_InitStructure);

}

uint16_t read_key_val(GPIO_TypeDef* GPIOx, uint16_t pin)
{
	uint16_t val = GPIO_ReadInputData(GPIOx);
	return (val & pin);
}

uint8_t scan_key(uint8_t mode)
{
	static uint8_t key=1;
	uint16_t val_up = read_key_val(KEY_UP_Port, KEY_UP_Pin);
	uint16_t val_left = read_key_val(KEY_Port, KEY_LEFT_Pin);
	uint16_t val_down = read_key_val(KEY_Port, KEY_DOWN_Pin);
	uint16_t val_right = read_key_val(KEY_Port, KEY_RIGHT_Pin);
	if(key==1&&(val_up!=0||val_left==0||val_down==0||val_right==0)) 
	{
		delay_ms(10);
		key=0;
		val_up = read_key_val(KEY_UP_Port, KEY_UP_Pin);
		val_left = read_key_val(KEY_Port, KEY_LEFT_Pin);
		val_down = read_key_val(KEY_Port, KEY_DOWN_Pin);
		val_right = read_key_val(KEY_Port, KEY_RIGHT_Pin);
		if(val_up!=0)
		{
		return KEY_UP;
		}
		else if(val_down==0)
		{
		return KEY_DOWN;
		}
		else if(val_left==0)
		{
		return KEY_LEFT;
		}
		else if(val_right==0)
		{
		return KEY_RIGHT;
		}
	}
	else if(val_up==0 && val_left!=0 && val_down!=0 && val_right!=0)
	{
		key=1;
	}
	if(mode==1) 
	{
		key=1;
	}
	return KEY_NONE;
}

void test_key()
{
	uint8_t key = KEY_NONE;
	uint16_t led_pin  = GPIO_Pin_2;
	init_systick();
	init_led();
	init_key();
	while(1){
		key = scan_key(0);
		if (KEY_UP == key){//点亮有时候失灵,原因待查
			set_led(led_pin, 0);
		}else if(KEY_DOWN == key){
			set_led(led_pin, 1);
		}

		delay_ms(300);
	}
}
