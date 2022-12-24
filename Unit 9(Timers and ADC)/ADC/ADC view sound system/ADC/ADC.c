/*
 * ADC.c
 *
 * Created: 12/7/2022 12:21:53 AM
 *  Author: Ayman
 */ 

#include "ADC.h"
//void (*G_fun)(void);
void ADC_Init(ADC_config_t * ADC_def)
{
	                                                     //set channel and Vref source
	ADMUX = (ADC_def->Vref<<6) |(ADC_def->channel <<0);
	
	ADCSRA |= (ADC_def->Interrupt <<3) ;
	ADCSRA |= (ADC_def->prescaler_div <<0) ;
	//G_fun =ADC_def->pt_callback_fun  ;
	   ADCSRA |=(1<<7) ;       //Enable ADC    
	
	    //start conversion 
}
uint16_t ADC_Read()
{
	uint16_t data ;
	ADCSRA |=(1<<6) ;   
	data = (uint16_t)(ADCL)| (uint16_t)(ADCH<<8);
	while ((ADCSRA  & (1<<4))==0) ;        //until flag set
	return ADC ;

}
/*ISR(ADC_vect)
{
	 G_fun();
}
*/