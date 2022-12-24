/*
 * ADC.c
 *
 * Created: 12/7/2022 12:21:02 AM
 * Author : Ayman Gamal
 */ 
#define  F_CPU 1000000UL
#include <avr/io.h>
#include  "ADC/ADC.h"

void Callbackfunction (void)
{
	PORTD =ADCL ;
	PORTC =ADCH ;
	ADCSRA |=(1<<6) ; //start conversion 
}
int main(void)
{
	DDRA =0 ;
	DDRD=0xff ;
	DDRC =0xff ;
	sei();
	ADC_config_t Config_st;
	Config_st.channel = channel_0;
	Config_st.Interrupt = Enable ;
	Config_st.prescaler_div = Divsion_128 ;
	Config_st.pt_callback_fun = Callbackfunction ;
	Config_st.Vref = Internal_2_56V_Voltage_Reference ;
	ADC_Init(&Config_st);
	
    /* Replace with your application code */
    while (1) ;
    
}

