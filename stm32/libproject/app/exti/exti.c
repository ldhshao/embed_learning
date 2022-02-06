#include "exti.h"
#include "../rcc/rcc.h"
#include "../led/led.h"
#include "../key/key.h"
#include <stm32f10x_exti.h>
#include <misc.h>

void init_exti0()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	init_systick();
	init_led();
	init_key();

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	//GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	//exti0: up
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	//exti3: down
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	//EXTI0 NVIC config: up
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//EXTI3 NVIC config: down
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
void EXTI0_IRQHandler()
{
	uint16_t led_pin  = GPIO_Pin_2;
	if(EXTI_GetITStatus(EXTI_Line0)==1)
	{
		delay_ms(10);
		if(read_key_val(KEY_UP_Port, KEY_UP_Pin) != 0)
		{
			set_led(led_pin, 0);
		}
	}
	
	EXTI_ClearITPendingBit(EXTI_Line0);
}

void EXTI3_IRQHandler()
{
	uint16_t led_pin  = GPIO_Pin_2;
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
		delay_ms(10);
		if(read_key_val(KEY_Port, KEY_DOWN_Pin) == 0)
		{
			set_led(led_pin, 1);
		}
	}
	
	EXTI_ClearITPendingBit(EXTI_Line3);
}
	