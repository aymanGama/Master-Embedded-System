/*
 * timer.c
 *
 * Created: 12/1/2022 1:33:11 PM
 *  Author: Ayman_gamal
 */ 

#include "timer.h"


/******************************************************************************
*                               GLOBAL VARIABLES                     *
*******************************************************************************/
Ptr_func_t CALLBACK_OVF ;
Ptr_func_t CALLBACK_CM ;
uint8_t u8_Time0_Overfl_Number;
Timeo_configure_t* TIMER0_Configurations;
/******************************************************************************
*                             APIS_Impelementaion                      *
*******************************************************************************/
void Timero_Init(Timeo_configure_t* time_config)
{
	TIMER0_Configurations =time_config ;
	TCCR0 |= TIMER0_Configurations->Mode;
	if((TIMER0_Configurations->Mode == Fast_PWM)  ||(TIMER0_Configurations->Mode == PWM_PhaseCorrect) )
	{
		TCCR0 |= 0x20 ;
	}
	
	TCCR0 |= TIMER0_Configurations->CLK ;
	TIMSK |= TIMER0_Configurations->TCTC_interrupt;
	TIMSK |= TIMER0_Configurations->TOV_interrupt ;
}
void Timero_Stop()
{
	TCCR0 &=~(7<<0);          //No clock source 
}
void Timer0_Set_overFlo_val(uint8_t value)
{
	u8_Time0_Overfl_Number = value;
	
}
void Timer0_get_overFlo_val(uint8_t*value)
{
	*value = u8_Time0_Overfl_Number ;
}
void Timer0_Set_Counter_val(uint8_t value)
{
	TCNT0 = value ;
}
void Timer0_get_Counter_val(uint8_t*value)
{
	*value = TCNT0 ;
}
void Timer0_Set_Compare_val(uint8_t value)
{
	OCR0 = value;
}
void Timer0_get_Compare_val(uint8_t*value)
{
	*value = OCR0;
}

void Timer0_overflowval_Interupt_Callback(Ptr_func_t callback )
{
	CALLBACK_OVF = callback ;
}
void Timer0_Compareval_Interupt_Callback(Ptr_func_t callback )
{
	CALLBACK_CM = callback ;
}
ISR(TIMER0_OVF_vect)
{
	CALLBACK_OVF();
}
ISR(TIMER0_COMP_vect)
{
	u8_Time0_Overfl_Number++;
	CALLBACK_CM();
}