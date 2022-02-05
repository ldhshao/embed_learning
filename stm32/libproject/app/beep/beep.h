#ifndef __BEEP_H
#define __BEEP_H

#include <stm32f10x.h>
#define BEEP_PORT GPIOB
#define BEEP_PIN  (GPIO_Pin_5)
#define BEEP_PORT_RCC RCC_APB2Periph_GPIOB

void test_beep(void);

#endif
