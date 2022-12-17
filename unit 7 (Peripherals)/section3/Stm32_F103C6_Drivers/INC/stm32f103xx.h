/*
 * stm32f103xx.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Ayman_Gamal
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdlib.h>
#include <stdint.h>



//-----------------------------
//Base addresses for Memories
//-----------------------------

#define SRAM_BASE                                            0x20000000UL
#define Flash_memory_BASE                                    0x08000000UL
#define Peripherals_BASE                                     0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE                  0xE0000000UL

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------

#define RCC_BASE                                             0x40021000UL


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-----------------------------
//Base addresses for APB2 BUS Peripherals
//-----------------------------


//GPIO
//A,B Fully Included in LQFP48 Package

#define GPIOA_BASE                                           0x40010800UL
#define GPIOB_BASE                                           0x40010C00UL

//C,D Partial Included in LQFP48 Package

#define GPIOC_BASE                                           0x40011000UL
#define GPIOD_BASE                                           0x40011400UL


//E,F,G is not Included in LQFP48 Package

#define GPIOE_BASE                                           0x40011800UL
#define GPIOF_BASE                                           0x40011C00UL
#define GPIOG_BASE                                           0x40012000UL

//AFIO
#define AFIO_BASE                                            0x40010000UL
//EXTI       (EXternal Interrupt)
#define EXTI_BASE                                            0x40010400UL

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-----------------------------
//Base addresses for APB2 BUS Peripherals
//-----------------------------





//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-----------------------------
//Peripheral register: GPIO
//-----------------------------
typedef struct
{
	volatile uint32_t CRL   ;                  //Port configuration register low
	volatile uint32_t CRH   ;                  //Port configuration register high
	volatile uint32_t IDR   ;                  //Port input data register
	volatile uint32_t ODR   ;                  //Port output data register
	volatile uint32_t BSRR  ;                  //Port bit set/reset register
	volatile uint32_t BRR   ;                  //Port bit reset register
	volatile uint32_t LCKR  ;                  //Port configuration lock register


}GPIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//-----------------------------
//Peripheral register: AFIO
//-----------------------------
typedef struct
{
	volatile uint32_t AFIO_EVCR      ;       //Event control register
	volatile uint32_t AFIO_MAPR      ;       //AF re map and debug I/O configuration register
	volatile uint32_t AFIO_EXTICR1   ;       //External interrupt configuration register 1
	volatile uint32_t AFIO_EXTICR2   ;       //External interrupt configuration register 2
	volatile uint32_t AFIO_EXTICR3   ;       //External interrupt configuration register 3
	volatile uint32_t AFIO_EXTICR4   ;       //External interrupt configuration register 4
	volatile uint32_t RESERVED       ;       //reserved
	volatile uint32_t AFIO_MAPR2     ;       //AF re map and debug I/O configuration register2


}AFIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//-----------------------------
//Peripheral register: EXTI
//-----------------------------
typedef struct
{
	volatile uint32_t EXTI_IMR     ;        //Interrupt mask register
	volatile uint32_t EXTI_EMR     ;        //Event mask register
	volatile uint32_t EXTI_RTSR    ;        //Rising trigger selection register
	volatile uint32_t EXTI_FTSR    ;        //Falling trigger selection register
	volatile uint32_t EXTI_SWIER   ;        //Software interrupt event register
	volatile uint32_t EXTI_PR      ;        //Pending register

}EXTI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-

//-----------------------------
//Peripheral register: RCC           (reset and clock controller)
//-----------------------------
typedef struct
{
	volatile uint32_t RCC_CR         ;      //Clock control register
	volatile uint32_t RCC_CFGR       ;      //Clock configuration register
	volatile uint32_t RCC_CIR        ;      //Clock interrupt register
	volatile uint32_t RCC_APB2RSTR   ;      //APB2 peripheral reset register
	volatile uint32_t RCC_APB1RSTR   ;      //APB1 peripheral reset register
	volatile uint32_t RCC_AHBENR     ;      //AHB peripheral clock enable register
	volatile uint32_t RCC_APB2ENR    ;      //APB2 peripheral clock enable register
	volatile uint32_t RCC_APB1ENR    ;      //APB1 peripheral clock enable register
	volatile uint32_t RCC_BDCR       ;      //Backup domain control register

}RCC_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-



//-----------------------------
//Peripheral Instants:
//-----------------------------
#define AFIO                     ((AFIO_Typedef *)AFIO_BASE)
#define EXTI                     ((EXTI_Typedef *)EXTI_BASE)
#define RCC                      ((RCC_Typedef *)RCC_BASE)
#define GPIOA                    ((GPIO_Typedef *)GPIOA_BASE)
#define GPIOB                    ((GPIO_Typedef *)GPIOB_BASE)
#define GPIOC                    ((GPIO_Typedef *)GPIOC_BASE)
#define GPIOD                    ((GPIO_Typedef *)GPIOD_BASE)
#define GPIOE                    ((GPIO_Typedef *)GPIOE_BASE)
#define GPIOF                    ((GPIO_Typedef *)GPIOF_BASE)
#define GPIOG                    ((GPIO_Typedef *)GPIOG_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-----------------------------
//clock enable Macros:
//-----------------------------
#define RCC_GPIOA_CLCK_ENABLE()         (RCC->RCC_APB2ENR |= 1<<2 )
#define RCC_GPIOB_CLCK_ENABLE()         (RCC->RCC_APB2ENR |= 1<<3 )
#define RCC_GPIOC_CLCK_ENABLE()         (RCC->RCC_APB2ENR |= 1<<4 )
#define RCC_GPIOD_CLCK_ENABLE()         (RCC->RCC_APB2ENR |= 1<<5 )
#define RCC_GPIOE_CLCK_ENABLE()         (RCC->RCC_APB2ENR |= 1<<6 )
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103XX_H_ */
