/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ayman Gamal
 * @brief          : toggle pin enable RCC for peripherals 
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


//LAB-2
// ENG:Ayman_Gamal
#include <stdint.h>
#include "stdlib.h"
#include "stdio.h"
#define  GPIO_BASE   (0x40010800)
#define  GPIO_CRH    *((volatile uint32_t*)(GPIO_BASE+0x04))
typedef volatile unsigned int vuint_t ;
#define RCC_BASE   (0x40021000)
#define  APB2ENR   *((volatile uint32_t*)(RCC_BASE+0x18))

// set ODR register using union and structure bitfield 
typedef union{
	vuint_t    all_field;
	struct {
		vuint_t first_bins:13 ;
		vuint_t p_13:1 ;
	} S_ODR;
}U_ODR_t;
volatile U_ODR_t* P_ODR=(volatile U_ODR_t*)(GPIO_BASE+0x0C);
void main(){
	volatile uint32_t i ;
//	Bit 2 IOPAEN: IO port A clock enable
//	Set and cleared by software.
//	0: IO port A clock disabled
//	1: IO port A clock enabled
//	volatile int i;
	APB2ENR |= 1<<2;
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;
	while(1){
		P_ODR->S_ODR.p_13 =1;
		for(i=0;i<5000;i++);
		P_ODR->S_ODR.p_13 =0;
		for(i=0;i<5000;i++);
	}
}

