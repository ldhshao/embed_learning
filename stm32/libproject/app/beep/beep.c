#include "beep.h"
#include "../rcc/rcc.h"

void init_beep()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin=BEEP_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE);
	GPIO_Init(BEEP_PORT,&GPIO_InitStructure);

	GPIO_ResetBits(BEEP_PORT,BEEP_PIN);
	//GPIO_SetBits(BEEP_PORT,BEEP_PIN);
}

void test_beep()
{
	init_systick();
	init_beep();
	while(1){
		GPIO_ResetBits(BEEP_PORT,BEEP_PIN);
		delay_ms(50);
		GPIO_SetBits(BEEP_PORT,BEEP_PIN);
		delay_ms(50);
	}
}
