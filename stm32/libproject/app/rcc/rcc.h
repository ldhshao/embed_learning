#ifndef __RCC_H
#define __RCC_H
//#include <stdint.h>
#include <stm32f10x_rcc.h>

void init_sysclk(uint32_t div, uint32_t pllm);
void init_systick(void);
void delay_ms(uint32_t nms);//nms < 1864

#endif
