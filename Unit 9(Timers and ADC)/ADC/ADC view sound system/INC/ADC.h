/*
 * ADC.h
 *
 * Created: 12/7/2022 12:22:08 AM
 *  Author: Ayman_Gamal
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include <avr/interrupt.h>

typedef enum
{
	Divsion_2 ,
	Divsion_2_also ,
	Divsion_4 ,
	Divsion_8 ,
	Divsion_16 ,
	Divsion_32 ,
	Divsion_64 ,
	Divsion_128 
	
}Prescaler_t;
typedef enum
{
	channel_0 ,
	channel_1 ,
	channel_2 ,
	channel_3 ,
	channel_4 ,
	channel_5 ,
	channel_6 ,
	channel_7
	
}channel_t;
typedef enum
{
	 
	Internal_Vref_turned_off       ,
	AVCC_with_external_capacitor   ,
	Reserved                       , 
	Internal_2_56V_Voltage_Reference
	
}Voltage_Reference_t ;
typedef enum
{
	
	Disable       ,
	Enable          ,
	
}Interrubt_t ;
typedef void(*P_interrupt_t)(void)    ;
typedef struct
{
	channel_t             channel                  ;
	Voltage_Reference_t   Vref                     ;
	Interrubt_t           Interrupt                ;
   	P_interrupt_t         pt_callback_fun          ; 
	Prescaler_t           prescaler_div            ;    
}ADC_config_t;

void ADC_Init(ADC_config_t * ADC_def);
uint16_t ADC_Read();




#endif /* ADC_H_ */