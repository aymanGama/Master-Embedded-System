/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ayman Gamal
 * @brief          : single and multy press on swiitch to toggle led
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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//RCC addresses
#define  RCC_BASE    (0x40021000)
#define  APP2ENR    *((volatile uint32_t*)(RCC_BASE+0x18))
//GPIOA addresses
#define  GPIOA_BASE   (0x40010800)
#define  GPIOA_CRH    *((volatile uint32_t*)(GPIOA_BASE+0x04))
#define  GPIOA_CRL    *((volatile uint32_t*)(GPIOA_BASE+0x00))
#define  GPIOA_ODR     *((volatile uint32_t*)(GPIOA_BASE+0x0C))
#define  GPIOA_IDR     *((volatile uint32_t*)(GPIOA_BASE+0x08))


//GPIOB addresses
#define  GPIOB_BASE   (0x40010C00)
#define  GPIOB_CRH    *((volatile uint32_t*)(GPIOB_BASE+0x04))
#define  GPIOB_CRL    *((volatile uint32_t*)(GPIOB_BASE+0x00))
#define  GPIOB_ODR     *((volatile uint32_t*)(GPIOB_BASE+0x0C))
#define  GPIOB_IDR     *((volatile uint32_t*)(GPIOB_BASE+0x08))



void Clock_init()
{
	//Enable Clock FOR (GPIOA, GPIOB)
	APP2ENR |=(1<<2);
	APP2ENR |=(1<<3);

}
void  config_CRL_CRH()
{
	//configuration registers for port (A ,B);
	GPIOA_ODR = 0;
	//set pin 1 As Input floating 
	GPIOA_CRL &= 0xffffff0f ;
	GPIOA_CRL |= 0x00000040 ;
	//set pin 13 As Input floating 

	GPIOA_CRH &= 0xff0fffff ;
	GPIOA_CRH |= 0x00400000 ;
	//set pin 1 As Output  push pull with max speed 10 Mhz 
	GPIOB_CRL &= 0xffffff0f ;
	GPIOB_CRL |= 0x00000010 ;
	//set pin 13 As Output  push pull with max speed 10 Mhz 

	GPIOB_CRH &= 0xff0fffff ;
	GPIOB_CRH |= 0x00100000 ;

}



void main(){
	Clock_init();
	config_CRL_CRH();
	while (1)
	{
		if (((GPIOA_IDR & (1<<1))>>1)==0)
		{
			GPIOB_ODR ^= 1<<1 ;
			while(((GPIOA_IDR & (1<<1))>>1)==0)     //For single pressing
			{
				;
			}
		}
		if (((GPIOA_IDR & (1<<13))>>13)==1)         //For multy pressing
		{
			GPIOB_ODR ^= 1<<13 ;

		}


	}

}








