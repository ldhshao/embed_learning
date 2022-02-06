#include "../app/led/led.h"
#include "../app/rcc/rcc.h"
#include "../app/beep/beep.h"
#include "../app/key/key.h"
#include "../app/exti/exti.h"

int main()
{
#if 0
	//init_sysclk(RCC_PLLSource_HSE_Div1, RCC_PLLMul_2);
	init_sysclk(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
	test_led1();
#endif
#if 0
	test_led2();
#endif
#if 0
	test_beep();
#endif
#if 0
	test_key();
#endif
#if 1
	init_exti0();
#endif
	
	return 0;
}
