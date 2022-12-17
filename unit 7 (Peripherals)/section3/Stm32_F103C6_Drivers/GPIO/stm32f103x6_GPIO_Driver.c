/*
 * stm32f103x6_GPIO_Driver.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Ayman_Gamal
 */

#include "stm32f103x6_gpio_Driver.h"
/**================================================================
 * @Fn            -MCAL_GPIO_INIT
 * @brief         - initialize GPIOx piny according to specified parameters in pinconfigure
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @param [in]    - pinconfigure : pointer to GPIO_PIN_config_t structure that contain
 *                  configuration information for specified  GPIO pin
 * @retval        -none
 * Note           -stm32f103c6 MCU has GPIO A,B,C,D,E modules
 *                 but LQFP48 package has GPIO A,B and part of C,E at external port
 */
uint8_t GPIO_CRLH_PinLocation (uint16_t pinNumber)
{
	switch(pinNumber)
	{
	case GPIO_PIN_0:
		return 0 ;
		break ;
	case GPIO_PIN_1:
		return 4 ;
		break ;
	case GPIO_PIN_2:
		return 8 ;
		break ;
	case GPIO_PIN_3:
		return 12 ;
		break ;
	case GPIO_PIN_4:
		return 16;
		break ;
	case GPIO_PIN_5:
		return 20;
		break ;
	case GPIO_PIN_6:
		return 24;
		break ;
	case GPIO_PIN_7:
		return 28;
		break ;

	case GPIO_PIN_8:
		return 0 ;
		break ;
	case GPIO_PIN_9:
		return 4 ;
		break ;
	case GPIO_PIN_10:
		return 8 ;
		break ;
	case GPIO_PIN_11:
		return 12 ;
		break ;
	case GPIO_PIN_12:
		return 16;
		break ;
	case GPIO_PIN_13:
		return 20;
		break ;
	case GPIO_PIN_14:
		return 24;
		break ;
	case GPIO_PIN_15:
		return 28;
		break ;


	}
	return 0 ;
}
void MCAL_GPIO_INIT (GPIO_Typedef * GPIOX ,GPIO_PIN_config_t * pinconfigure)
{
	volatile uint32_t * configregister = NULL ;
	//	Port configuration register low (GPIOx_CRL) from pin (0 to7)
	//	Port configuration register high (GPIOx_CRH)from pin (8 to 15 )
	configregister = (pinconfigure->GPIO_PIN_Numbers < GPIO_PIN_8)? &GPIOX->CRL : &GPIOX->CRH ;
	// clear CNF,MODE in CRL,H for pin
	(*configregister) &= ~(0xf << GPIO_CRLH_PinLocation(pinconfigure->GPIO_PIN_Numbers)) ;

	// check pin is output
	volatile uint8_t pinconfig = 0 ;
	if ((pinconfigure->GPIO_PIN_MODE ==PIN_MODE_OUT_PP) || (pinconfigure->GPIO_PIN_MODE ==PIN_MODE_OUT_OD) || (pinconfigure->GPIO_PIN_MODE ==PIN_MODE_OUT_AF_OD) || (pinconfigure->GPIO_PIN_MODE ==PIN_MODE_OUT_AFPP))
	{
		//pin is output

		pinconfig = ( (((pinconfigure->GPIO_PIN_MODE - 4) << 2) | (pinconfigure->GPIO_OUTPIN_Speed) ) & 0x0f);


	}
	else
	{
		//pin is input set CNF in CRL,H for pin ,MODE=00
		if ((pinconfigure->GPIO_PIN_MODE == PIN_MODE_IN_AI) || (pinconfigure->GPIO_PIN_MODE == PIN_MODE_IN_FI))
		{
			pinconfig = ( (pinconfigure->GPIO_PIN_MODE << 2) & 0x0f);

		}
		//input alternate function consider it as input floating
		else if (pinconfigure->GPIO_PIN_MODE == PIN_MODE_IN_AF)
		{
			pinconfig = ( (PIN_MODE_IN_FI << 2) & 0x0f);

		}
		// pin is input pull up or pull down all of them have the same number so to different between them
		//from data sheet  and table 20 and differ from ODR register
		else
		{
			pinconfig = ( (PIN_MODE_IN_PU << 2) & 0x0f);

			if (pinconfigure->GPIO_PIN_MODE == PIN_MODE_IN_PU)
			{
				// Port bit configuration as input pull up set ODR =1 for this pin
				GPIOX->ODR |= (pinconfigure->GPIO_PIN_Numbers);
			}
			else
			{
				// Port bit configuration as input pull down set ODR =0 for this pin

				GPIOX->ODR &= ~(pinconfigure->GPIO_PIN_Numbers);
			}
		}
	}
	// write on CNF,MODE in CRL or CRH for pin
	(*configregister) |= ((pinconfig) << GPIO_CRLH_PinLocation(pinconfigure->GPIO_PIN_Numbers)) ;
}


/**================================================================
 * @Fn            -MCAL_GPIO_DEINIT
 * @brief         -Reset all the GPIO registers
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @retval        -none
 * Note           -none
 */

void MCAL_GPIO_DEINIT (GPIO_Typedef * GPIOX)
{
/* use it if i do not have reset controller
	// reset GPIO port manually
	//reset all registers
	//	GPIOX->CRL  = 0x44444444 ;
	//	GPIOX->CRH  = 0x44444444 ;
	//	GPIOX->IDR  = 0x0000     ;
	//	GPIOX->ODR  = 0x00000000 ;
	//	GPIOX->BRR  = 0x00000000 ;
	//	GPIOX->BSRR = 0x00000000 ;
	//	GPIOX->LCKR = 0x00000000 ;

*/
	// reset GPIO port using reset register
	//APB2 peripheral reset register (RCC_APB2RSTR
	if(GPIOX== GPIOA)
	{
		RCC->RCC_APB2RSTR |=GPIO_PIN_2 ;
		RCC->RCC_APB2RSTR &=~GPIO_PIN_2 ;

	}
	else if (GPIOX== GPIOB)
	{
		RCC->RCC_APB2RSTR |=GPIO_PIN_3 ;
		RCC->RCC_APB2RSTR &=~GPIO_PIN_3 ;

	}
	else if (GPIOX== GPIOC)
	{
		RCC->RCC_APB2RSTR |=GPIO_PIN_4 ;
		RCC->RCC_APB2RSTR &=~GPIO_PIN_4 ;

	}
	else if (GPIOX== GPIOD)
	{
		RCC->RCC_APB2RSTR |=GPIO_PIN_5 ;
		RCC->RCC_APB2RSTR &=~GPIO_PIN_5 ;

	}
	else if (GPIOX== GPIOE)
	{
		RCC->RCC_APB2RSTR |=GPIO_PIN_6 ;
		RCC->RCC_APB2RSTR &=~GPIO_PIN_6 ;

	}

}

/**================================================================
 * @Fn            -MCAL_GPIO_ReadPin
 * @brief         - Read specific PIN
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @param [in]    - pinNumber : pin number according to @ref GPIO_PINS_DEFINE
 * @retval        -the input pin value according to @ref GPIO_PIN_STATE
 */

uint8_t  MCAL_GPIO_ReadPin(GPIO_Typedef *GPIOX , uint16_t pinNumber)
{
	uint8_t bitstatus ;
	if((GPIOX->IDR & pinNumber) != (uint32_t)GPIO_PIN_RESET )
	{
		bitstatus = GPIO_PIN_SET ;
	}
	else
	{
		bitstatus = GPIO_PIN_RESET ;
	}
	return bitstatus ;
}

/**================================================================
 * @Fn            -MCAL_GPIO_ReadPort
 * @brief         - Read specific Port
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @retval        -the input port value
 * Note           -none
 */


uint16_t  MCAL_GPIO_ReadPort(GPIO_Typedef *GPIOX )
{
	uint16_t port_value ;
	port_value =(uint16_t)(GPIOX->IDR) ;
	return port_value ;

}



/**================================================================
 * @Fn            -MCAL_GPIO_WritePin
 * @brief         - write on specific PIN
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @param [in]    - pinNumber : pin number will write on it  according to @ref GPIO_PINS_DEFINE
 * @param [in]    - Value : Value write on pin
 * @retval        -none
 */

void  MCAL_GPIO_WritePin(GPIO_Typedef *GPIOX , uint16_t pinNumber, uint8_t Value)
{
	if (Value != GPIO_PIN_RESET )
	{
		// GPIOX->ODR |= pinNumber;

		//or

//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
//		These bits are write-only and can be accessed in Word mode only.
//		0: No action on the corresponding ODRx bit
//		1: Set the corresponding ODRx bit

		GPIOX->BSRR =(uint32_t)pinNumber ;
	}
	else
	{
//		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
//		These bits are write-only and can be accessed in Word mode only.
//		0: No action on the corresponding ODRx bit
//		1: Reset the corresponding ODRx bit
		GPIOX->BRR = (uint32_t)pinNumber ;
	}

}

/**================================================================
 * @Fn            -MCAL_GPIO_WritePort
 * @brief         - write on specific Port
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @param [in]    - Value : Value write on port
 * @retval        -none
 */


void  MCAL_GPIO_WritePort(GPIO_Typedef *GPIOX , uint16_t Value)
{
	GPIOX->ODR = (uint32_t)Value ;

}

/**================================================================
 * @Fn            -MCAL_GPIO_Toggle_PIN
 * @brief         - toggle specific Pin
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @param [in]    - pinNumber : pin number that will be toggled according to @ref GPIO_PINS_DEFINE
 * @retval        -none
 */


void MCAL_GPIO_Toggle_PIN (GPIO_Typedef * GPIOX ,uint16_t PinNumber)
{
	GPIOX->ODR ^= (uint32_t)PinNumber ;

}
/**================================================================
 * @Fn            -MCAL_GPIO_Lock_PIN
 * @brief         - the lock pin mechanism allows the IO configuration to be  frozen
 * @param [in]    - GPIOX :where X can be (A,B,C,D,E depending on device used) select GPIO peripheral from it
 * @param [in]    - pinNumber : pin number that will be locked according to @ref GPIO_PINS_DEFINE
 * @retval        -ok if pin is locked  and Error if pin is not locked (OK & ERROR are defined @ref GPIO_Return_LOCK
 */


uint8_t MCAL_GPIO_Lock_PIN (GPIO_Typedef* GPIOX,uint16_t PinNumber)
{
//	Bit 16 LCKK[16]: Lock key
//	This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock.

//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
//	These bits are read write but can only be written when the LCKK bit is 0.
//	0: Port configuration not locked
//	1: Port configuration locked.

	// set LCKK[16]: Lock key
	uint32_t temp = 1<<16 ;
	//set  LCKy: Port x Lock bit y (y= 0 .. 15)
	temp |= (uint32_t)PinNumber ;
	//	Write 1
	GPIOX->LCKR = temp ;
	//	Write 0
	GPIOX->LCKR =(uint32_t)PinNumber ;
	//	Write 1
	GPIOX->LCKR = temp ;
	//	Read 0
	 temp  =  GPIOX->LCKR ;
	//	Read 1 (this read is optional but confirms that the lock is active)
	 if (GPIOX->LCKR & 1<<16 )
	 {
		 return GPIO_LOCK_ENABLED ;
	 }
	 else
		 return GPIO_LOCK_ERROR ;

}

void MCAL_GPIO_Write_Nibble(GPIO_Typedef * GPIOx ,uint8_t GPIO_Nibble_Number,uint8_t Value)
{
	if(GPIO_Nibble_Number==GPIO_FIRST_NIBBLE)
	{
		Value =Value & 0x0f;
		GPIOx->ODR &= 0xFFF0;
		GPIOx->ODR |=(uint8_t)Value;
	}
	else if(GPIO_Nibble_Number==GPIO_SECOND_NIBBLE)
	{
		Value =Value & 0x0f;
		GPIOx->ODR &= 0xFF0F;
		GPIOx->ODR |=((uint8_t)Value<<4);
	}
	else if(GPIO_Nibble_Number==GPIO_THIRD_NIBBLE)
	{
		Value =Value & 0x0f;
		GPIOx->ODR &= 0xF0FF;
		GPIOx->ODR |=((uint8_t)Value<<8);
	}
	else if(GPIO_Nibble_Number==GPIO_FOURTH_NIBBLE)
	{
		Value =Value & 0x0f;
		GPIOx->ODR &= 0x0FFF;
		GPIOx->ODR |=((uint8_t)Value<<12);
	}
}

