#include "rcc.h"
#include <misc.h>

uint32_t fac_ms = 0;

void init_sysclk(uint32_t div, uint32_t pllm)
{
	RCC_DeInit(); 
	RCC_HSEConfig(RCC_HSE_ON);
	if(RCC_WaitForHSEStartUp()==SUCCESS) 
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		RCC_PLLConfig(div,pllm);//
		RCC_PLLCmd(ENABLE); //
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//
		while(RCC_GetSYSCLKSource()!=0x08);//
	}
}

void init_systick()
{
	init_sysclk(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_ms = 9000;
}
void delay_ms(uint32_t nms)//nms < 1864
{
	uint32_t tmp = 0;
	
	SysTick->CTRL = 0;
	SysTick->LOAD = (nms * fac_ms);
	SysTick->VAL = 0;
	SysTick->CTRL = 1;
	
	do{
		tmp = SysTick->CTRL;
	}while((0 != (tmp&1)) && (1 != (tmp>>16)));
	
	SysTick->VAL = 0;
	SysTick->CTRL = 0;
}
