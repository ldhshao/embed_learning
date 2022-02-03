#include "stm32f10x.h"

#define RCC_APB2ENR     *(unsigned int*)(0x40021018)
#define GPIOC_CRL       *(unsigned int*)(0x40011000)
#define GPIOC_ODR       *(unsigned int*)(0x4001100C)
	
void SystemInit()
{
}

int main()
{
	RCC_APB2ENR |= (1<<4);
	GPIOC_CRL |= (0x1<<(4*0));
	GPIOC_ODR = ~(0x1<<(0));
	return 0;
}
