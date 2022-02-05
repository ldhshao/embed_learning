#ifndef __KEY_H
#define __KEY_H

#include <stm32f10x.h>

#define KEY_LEFT_Pin GPIO_Pin_2
#define KEY_DOWN_Pin GPIO_Pin_3
#define KEY_RIGHT_Pin GPIO_Pin_4
#define KEY_UP_Pin GPIO_Pin_0

#define KEY_Port (GPIOE) //
#define KEY_PORT_RCC RCC_APB2Periph_GPIOE
#define KEY_UP_Port (GPIOA) //
#define KEY_UP_PORT_RCC RCC_APB2Periph_GPIOA

#define KEY_NONE 0
#define KEY_UP   1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4

void init_key(void);
uint8_t scan_key(uint8_t mode);
uint16_t read_key_val(GPIO_TypeDef* GPIOx, uint16_t pin);
void test_key(void);

#endif
