/*
 * timer.h
 *
 * Created: 12/1/2022 1:33:25 PM
 *  Author: Ayman
 */ 


#ifndef TIMER_H_
#define TIMER_H_


/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>



/******************************************************************************
*                              enum_definition 			                          *
*******************************************************************************/

typedef  void(*Ptr_func_t)(void);

typedef enum                    //Timer Counter Control Register  TCCR0
{                              // not use OC0 as out put
	Normal,                    
	PWM_PhaseCorrect = 0x40,
	CTC=0x08,
	Fast_PWM=0x48
}Timer0_Mode_t;
typedef enum 
{
	No_clock_source,
	clk_prescaling_0,
	clk_prescaling_8,
	clk_prescaling_64,
	clk_prescaling_256,
	clk_prescaling_1024,
	Externalclock_falling ,
	Externalclock_raising ,
	 
}Clk_mode_t;

typedef enum                      //Timer Counter Interrupt Mask Register  TIMSK
{
	Overfl_Inter_Enable =0x01,               //TOIE0
	Overfl_Inter_disable=0x00
	
}Inter_overflow_t;
typedef enum                    
{
	Comp_Inter_Enable=0x02   ,              //OCIE0
	Comp_Inter_disable=0x00
	
}Inter_ctc_t;	                                         

/******************************************************************************
*                              structure 			                          *
*******************************************************************************/

typedef struct
{
	
	Timer0_Mode_t          Mode         ;
	Clk_mode_t             CLK          ;
	Inter_overflow_t    TOV_interrupt   ;
	Inter_ctc_t         TCTC_interrupt  ;
}Timeo_configure_t;


/******************************************************************************
*                             APIS		                          *
*******************************************************************************/

void Timero_Init(Timeo_configure_t* time_config);
void Timero_Stop();
void Timer0_Set_overFlo_val(uint8_t value);
void Timer0_get_overFlo_val(uint8_t*value);
void Timer0_Set_Counter_val(uint8_t value);
void Timer0_get_Counter_val(uint8_t*value);
void Timer0_Set_Compare_val(uint8_t value);
void Timer0_get_Compare_val(uint8_t*value);

void Timer0_overflowval_Interupt_Callback(Ptr_func_t callback );
void Timer0_Compareval_Interupt_Callback(Ptr_func_t callback );




#endif /* TIMER_H_ */