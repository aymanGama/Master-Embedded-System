/*
 * EXTI.c
 *
 *  Created on: Nov 13, 2022
 *      Author: DR-Mosaad
 */

//includes
#include "stm32f103x6_EXTI_DRIVER.h"
#include "stm32f103x6_gpio_Driver.h"


//-------------------------------------------------------------------------------
//                                      Generic Variables
//--------------------------------------------------------------------------------


void (*GP_IRQ_callback[15])(void);





//-------------------------------------------------------------------------------
//                                      Generic Macro
//--------------------------------------------------------------------------------
#define AFIO_GPIO_EXTI_PORT_Mapping(x)          (     (x==GPIOA)?0:\
		                                              (x==GPIOB)?1:\
                                                      (x==GPIOC)?2:\
                                                      (x==GPIOD)?3:0    )

//--------------------------------------------------------------------------------
//                                      Generic Function
//--------------------------------------------------------------------------------


void Enable_NVIC(uint8_t IRQ_NUM)
{
	switch (IRQ_NUM)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable ;
		break ;
	case 1:
		NVIC_IRQ7_EXTI1_Enable ;
		break ;
	case 2:
		NVIC_IRQ8_EXTI2_Enable ;
		break ;
	case 3:
		NVIC_IRQ9_EXTI3_Enable ;
		break ;
	case 4:
		NVIC_IRQ10_EXTI4_Enable ;
		break ;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable ;
		break ;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable ;
		break ;
	}

}
void Disable_NVIC(uint8_t IRQ_NUM)
{
	switch (IRQ_NUM)
		{
		case 0:
			NVIC_IRQ6_EXTI0_Disable ;
			break ;
		case 1:
			NVIC_IRQ7_EXTI1_Disable ;
			break ;
		case 2:
			NVIC_IRQ8_EXTI2_Disable ;
			break ;
		case 3:
			NVIC_IRQ9_EXTI3_Disable ;
			break ;
		case 4:
			NVIC_IRQ10_EXTI4_Disable ;
			break ;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_Disable ;
			break ;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI10_15_Disable ;
			break ;
		}
}












void Update_EXTI(EXTI_PinConfig_t*  EXTI_Config)
{

//1- configure GPIO pin to be alternative input >>>>>> floating input
	GPIO_PIN_config_t Pinconf ;
	Pinconf.GPIO_PIN_Numbers = EXTI_Config->EXTI_PIN.GPIO__Pin ;
	Pinconf.GPIO_PIN_MODE    = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(EXTI_Config->EXTI_PIN.GPIO_Port,&Pinconf) ;

//-------------------------------------------------------------------------------------------

//2- set AFIO Registers for EXTIline and GPIO pin
	//know registers to be used
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers / 4 ;
	uint8_t AFIO_EXTICR_bitfield_position = (EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers % 4)*4 ;
	//set it zero to delete value in it
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index] &=~(0xf<<AFIO_EXTICR_bitfield_position);
	// set the value for port and AFIO_EXTIR
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_PORT_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port )&0xf) << AFIO_EXTICR_bitfield_position);

//-----------------------------------------------------------------------------------------------------------

//3- Update rising Falling Trigger
	//set it zero at first to make sure it is not refer to anything
	//EXTI->EXTI_RTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);
	//EXTI->EXTI_FTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);

	EXTI->EXTI_RTSR =0;
	EXTI->EXTI_FTSR=0;
	if(EXTI_Config->trigger_Case == EXTI_TRIGGER_RISING)
	{
		EXTI->EXTI_RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);

	}
	else if(EXTI_Config->trigger_Case ==EXTI_TRIGGER_FALLING)
	{
		EXTI->EXTI_FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);

	}
	else if(EXTI_Config->trigger_Case ==EXTI_TRIGGER_BOTH_RF)
	{
		EXTI->EXTI_RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);
		EXTI->EXTI_FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);

	}
//--------------------------------------------------------------------------------------------------------------


//4- update IRQ Handling CallBack

	GP_IRQ_callback[EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers] = EXTI_Config->P_IRQ_callback ;


//5- Enable /Disable IRQ Mask IMR, NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->EXTI_IMR |= 1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers ;
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);
	}
	else
	{
		EXTI->EXTI_IMR |=~(1<<EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers) ;
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_Input_LineNumbers);
	}

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
                                          // ISR FUNCTION
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


void EXTI0_IRQHandler(void)
{
	// clear pending interrupt from pending register clear by write 1
	EXTI->EXTI_PR |= (1<<0);
	GP_IRQ_callback[0]();

}

void EXTI1_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1<<1);
	GP_IRQ_callback[1]();
}
void EXTI2_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1<<2);
	GP_IRQ_callback[2]();

}
void EXTI3_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1<<3);
	GP_IRQ_callback[3]();

}
void EXTI4_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1<<4);


	GP_IRQ_callback[4]();
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI->EXTI_PR & 1<<5 )      {EXTI->EXTI_PR |= (1<<5) ;  GP_IRQ_callback[5]();}
	if(EXTI->EXTI_PR & 1<<6 )      {EXTI->EXTI_PR |= (1<<6) ;  GP_IRQ_callback[6]();}
	if(EXTI->EXTI_PR & 1<<7 )      {EXTI->EXTI_PR |= (1<<7) ;  GP_IRQ_callback[7]();}
	if(EXTI->EXTI_PR & 1<<8 )      {EXTI->EXTI_PR |= (1<<8) ;  GP_IRQ_callback[8]();}
	if(EXTI->EXTI_PR & 1<<9 )      {EXTI->EXTI_PR |= (1<<9) ;  GP_IRQ_callback[9]();}



}
void EXTI15_10_IRQHandler(void)
{
	if((EXTI->EXTI_PR & (1<<10))==1)      {	EXTI->EXTI_PR |= (1<<10); GP_IRQ_callback[10]();}
	if((EXTI->EXTI_PR & (1<<11))==1)      {	EXTI->EXTI_PR |= (1<<11); GP_IRQ_callback[11]();}
	if((EXTI->EXTI_PR & (1<<12))==1)      {	EXTI->EXTI_PR |= (1<<12); GP_IRQ_callback[12]();}
	if((EXTI->EXTI_PR & (1<<13))==1)      {	EXTI->EXTI_PR |= (1<<13); GP_IRQ_callback[13]();}
	if((EXTI->EXTI_PR & (1<<14))==1)      {	EXTI->EXTI_PR |= (1<<14); GP_IRQ_callback[14]();}
	if((EXTI->EXTI_PR & (1<<15))==1)      {	EXTI->EXTI_PR |= (1<<15); GP_IRQ_callback[15]();}

}









//----------------------------------------------------------------------------------------------------------
//                                                  MCAL APIS
//-----------------------------------------------------------------------------------------------------------

/**================================================================
 * @Fn            -MCAL_EXTI_GPIO_INIT
 * @brief         - this is used to initialize EXTI from specific GPIO Pin and specify the mask /trigger condition and call back
 * @param [in]    - EXTI_Config set by @ ref EXTI_define ,EXTI_Trigger_define and EXTI_IRQ_define
 * @retval        -none
 * Note           -stm32f103c6 MCU has GPIO A,B,C,D,E modules
 *                 but LQFP48 package has GPIO A,B and part of C,E at external port
 *                 also mandatory to enable RCC cLock for AFIO and the corresponding GPIO
 */


void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);


}



/**================================================================
 * @Fn            -MCAL_EXTI_GPIO_DEINIT
 * @brief         - reset all EXTI Registers  and NVIC corresponding mask
 * @param [in]    - none
 * @param [in]    - none
 * @retval        -none
 * Note           -stm32f103c6 MCU has GPIO A,B,C,D,E modules
 *                 but LQFP48 package has GPIO A,B and part of C,E at external port
 */

void MCAL_EXTI_GPIO_DEINIT(void)
{
	//reset all EXTI registers
	EXTI->EXTI_IMR   =   0x00000000 ;
	EXTI->EXTI_EMR   =   0x00000000 ;
	EXTI->EXTI_RTSR  =   0x00000000 ;
	EXTI->EXTI_FTSR  =   0x00000000 ;
	EXTI->EXTI_SWIER =   0x00000000 ;
//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->EXTI_PR    =   0xffffffff ;

// Disable EXTI IRQ from NVIC


	NVIC_IRQ6_EXTI0_Disable       ;
	NVIC_IRQ7_EXTI1_Disable       ;
	NVIC_IRQ8_EXTI2_Disable       ;
	NVIC_IRQ9_EXTI3_Disable       ;
	NVIC_IRQ10_EXTI4_Disable      ;
	NVIC_IRQ23_EXTI5_9_Disable    ;
	NVIC_IRQ40_EXTI10_15_Disable  ;
}

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

void MCAL_EXTI_GPIO_UPdate(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);

}
