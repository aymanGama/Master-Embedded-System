/*
 * stm32f103c6.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Ayman_Gamal
 */

#ifndef INC_STM32F103X6_GPIO_DRIVER_H_
#define INC_STM32F103X6_GPIO_DRIVER_H_

//----------------------------- 29
//Includes
//-----------------------------
#include "stm32f103xx.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint16_t GPIO_PIN_Numbers         ;                  //specifies the gpio pins to be configured.
	                                                     //this parameter  be a value of @ref GPIO_PINS_DEFINE

	uint8_t  GPIO_PIN_MODE            ;                  //specifies the operating mode for the selected pin
	                                                     //this parameter  be a value of @ref GPIO_PINS_MODE_DEFINE

	uint8_t  GPIO_OUTPIN_Speed        ;                  // specifies the speed of out pin
	                                                     //this parameter  be a value of @ref GPIO_SPEED_DEFINE
}GPIO_PIN_config_t;





//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref GPIO_PINS_DEFINE
*/
#define GPIO_PIN_0           ((uint16_t)0x0001)        //select PIN 0
#define GPIO_PIN_1           ((uint16_t)0x0002)        //select PIN 1
#define GPIO_PIN_2           ((uint16_t)0x0004)        //select PIN 2
#define GPIO_PIN_3           ((uint16_t)0x0008)        //select PIN 3
#define GPIO_PIN_4           ((uint16_t)0x0010)        //select PIN 4
#define GPIO_PIN_5           ((uint16_t)0x0020)        //select PIN 5
#define GPIO_PIN_6           ((uint16_t)0x0040)        //select PIN 6
#define GPIO_PIN_7           ((uint16_t)0x0080)        //select PIN 7
#define GPIO_PIN_8           ((uint16_t)0x0100)        //select PIN 8
#define GPIO_PIN_9           ((uint16_t)0x0200)        //select PIN 9
#define GPIO_PIN_10          ((uint16_t)0x0400)        //select PIN 10
#define GPIO_PIN_11          ((uint16_t)0x0800)        //select PIN 11
#define GPIO_PIN_12          ((uint16_t)0x1000)        //select PIN 12
#define GPIO_PIN_13          ((uint16_t)0x2000)        //select PIN 13
#define GPIO_PIN_14          ((uint16_t)0x4000)        //select PIN 14
#define GPIO_PIN_15          ((uint16_t)0x8000)        //select PIN 15
#define GPIO_ALL_PIN         ((uint16_t)0xffff)        //select  ALL PINS in port



//@ref GPIO_PIN_STATE
#define GPIO_PIN_SET          1
#define GPIO_PIN_RESET        0


// @ref GPIO_Return_LOCK
#define GPIO_LOCK_ENABLED          1
#define GPIO_LOCK_ERROR            0







/*@ref GPIO_SPEED_DEFINE
01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.
*/
#define PIN_OUT_SPEED_10                  (0x00000001u)       //01: Output mode, max speed 10 MHz.
#define PIN_OUT_SPEED_2                   (0x00000002u)       //10: Output mode, max speed 2 MHz.
#define PIN_OUT_SPEED_50                  (0x00000003u)       //11: Output mode, max speed 50 MHz.




/*@ref GPIO_PINS_MODE_DEFINE
*/
//In input mode (MODE[1:0]=00):

#define PIN_MODE_IN_AI                  0x00000000u       //00: Analog mode
#define PIN_MODE_IN_FI                  0x00000001u       //01: Floating input (reset state)
#define PIN_MODE_IN_PU					0x00000002u	    //10: Input with pull-up
#define PIN_MODE_IN_PD					0x00000003u       //11: Input with pull-down (HINT: it should be 0b10 in cnf but i make it 11 now)
//In output mode (MODE[1:0] > 00):
#define PIN_MODE_OUT_PP					0x00000004u	    //00: General purpose output push-pull
#define PIN_MODE_OUT_OD					0x00000005u	    //01: General purpose output Open-drain
#define PIN_MODE_OUT_AFPP				0x00000006u	    //10: Alternate function output Push-pull
#define PIN_MODE_OUT_AF_OD				0x00000007u	    //11: Alternate function output Open-drain
#define PIN_MODE_IN_AF				    0x00000008u	    // Alternate function INPUT






/*
* =======================================================================================
*                              APIs Supported by "MCAL GPIO DRIVER"
* =======================================================================================
*/
void MCAL_GPIO_INIT (GPIO_Typedef * GPIOX ,GPIO_PIN_config_t * pinconfigure);
void MCAL_GPIO_DEINIT (GPIO_Typedef * GPIOX);
//                                 APIS for READ
uint8_t  MCAL_GPIO_ReadPin(GPIO_Typedef *GPIOX , uint16_t pinNumber);
uint16_t  MCAL_GPIO_ReadPort(GPIO_Typedef *GPIOX );
//                                 APIS for WRITE
void  MCAL_GPIO_WritePin(GPIO_Typedef *GPIOX , uint16_t pinNumber, uint8_t Value);
void  MCAL_GPIO_WritePort(GPIO_Typedef *GPIOX , uint16_t Value);
//------------------------------------------------------------------
void MCAL_GPIO_Toggle_PIN (GPIO_Typedef * GPIOX ,uint16_t PinNumber);

uint8_t MCAL_GPIO_Lock_PIN (GPIO_Typedef* GPIOX,uint16_t PinNumber);







#endif /* INC_STM32F103X6_GPIO_DRIVER_H_ */
