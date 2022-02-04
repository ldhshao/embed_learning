#include "led.h"
#include "../rcc/rcc.h"

void init_led()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin=LED_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(LED_PORT_RCC,ENABLE);
	GPIO_Init(LED_PORT,&GPIO_InitStructure);

	GPIO_SetBits(LED_PORT,LED_PIN);
}
void delay(int ms)
{
	int cnt = 50000*ms;
	int i = 0;
	for (; i < cnt; i++);
}
void test_led1()
{
	init_led();
	while(1){
		GPIO_ResetBits(LED_PORT,GPIO_Pin_1);
		delay(1000);
		GPIO_SetBits(LED_PORT,GPIO_Pin_1);
		delay(1000);
	}
}

void test_led2()
{
	init_systick();
	init_led();
	while(1){
		GPIO_ResetBits(LED_PORT,GPIO_Pin_1);
		delay_ms(1000);
		GPIO_SetBits(LED_PORT,GPIO_Pin_1);
		delay_ms(1000);
	}
}
