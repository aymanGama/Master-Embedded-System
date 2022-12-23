/*
 * timers.c
 *
 * Created: 12/1/2022 1:32:38 PM
 * Author : Ayman_gamal
 */ 
#define F_CPU 8000000UL

#include "timer/timer.h"
extern uint8_t u8_Time0_Overfl_Number ;


void TIMER0_COM_Interrupt()
{
	PORTB |=(1<<0);
}
void TIMER0_OVFLO_Interrupt()
{
	PORTB &=~(1<<0);
}


int main(void)
{
	//**********************************************************************************************
	//                        PWM using interrupt NORMAL mode
	//********************************************************************************************** 
   /* DDRA = 0xff; DDRB=0xff;
	sei();                                  // enable global interrupt controller
	Timer0_Compareval_Interupt_Callback(TIMER0_COM_Interrupt);
	Timer0_overflowval_Interupt_Callback(TIMER0_OVFLO_Interrupt);
	Timer0_Set_Compare_val(0xf0);
	Timer0_Set_overFlo_val(0xff);
	Timeo_configure_t t_config   ={Normal , clk_prescaling_8 , Overfl_Inter_Enable , Comp_Inter_Enable};
	Timero_Init(&t_config);	
    while (1) 
    {
    }
	
	*/
	//*****************************************************************************************************
	                   //PWM using fast PWM
    //******************************************************************************************************** 
	
       DDRB |= (1<<3);             
	Timer0_Set_Compare_val(0x0f);
	Timer0_Set_overFlo_val(0xff);
	Timeo_configure_t t_config   ={Fast_PWM , clk_prescaling_64 , Overfl_Inter_disable , Comp_Inter_disable};
	Timero_Init(&t_config);
	while (1)
	{
	}
	//****************************************************************************************
	                         //PWM_PhaseCorrect
   //*****************************************************************************************
	 /*  DDRB |= (1<<3);
	   Timer0_Set_Compare_val(0x01);
	   Timer0_Set_overFlo_val(0xff);
	   Timeo_configure_t t_config   ={PWM_PhaseCorrect , clk_prescaling_8 , Overfl_Inter_disable , Comp_Inter_disable};
	   Timero_Init(&t_config);
	   while (1)
	   {
	   }
	   */
}

