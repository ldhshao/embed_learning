#include "../app/led/led.h"
#include "../app/rcc/rcc.h"

int main()
{
#if 0
	//init_sysclk(RCC_PLLSource_HSE_Div1, RCC_PLLMul_2);
	init_sysclk(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
	test_led1();
#endif
#if 1
	test_led2();
#endif
	
	return 0;
}
