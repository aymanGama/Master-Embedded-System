/*
 * KEYPAD.h
 *
 * Created: 11/6/2022 5:13:17 AM
 *  Author: Ayman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "stm32f103x6_gpio_Driver.h"
#include "stm32f103xx.h"
#define KEYPAD_PORT     GPIOB
//#define DATADIR_KEYPAD  DDRD
//#define KEYPAD_PIN      PIND
#define R0  GPIO_PIN_0
#define R1  GPIO_PIN_1
#define R2  GPIO_PIN_3
#define R3  GPIO_PIN_4
#define C0  GPIO_PIN_5
#define C1  GPIO_PIN_6
#define C2  GPIO_PIN_7
#define C3  GPIO_PIN_8
void KEYBAD_INIT();
char KEYPAD_GET_CHAR();





#endif /* KEYPAD_H_ */
