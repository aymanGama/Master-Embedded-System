/*
 * ADC with LCD.c
 *
 * Created: 12/24/2022 8:35:15 PM
 * Author : Ayman_Gamal
 */ 
#define  F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include  "INC/ADC.h"
#include  "INC/lcd.h"


/*void Callbackfunction (void)
{
	PORTD =ADCL ;
	PORTC =ADCH ;
	ADCSRA |=(1<<6) ; //start conversion
}*/
int main(void)
{
	LCD_init();
	DDRA=0xff ;
	DDRB =0xff ;
	//sei();
	ADC_config_t Config_st;
	Config_st.channel = channel_0;
	Config_st.Interrupt = Disable ;
	Config_st.prescaler_div = Divsion_128 ;
	//Config_st.pt_callback_fun = Callbackfunction ;
	Config_st.Vref = AVCC_with_external_capacitor ;
	ADC_Init(&Config_st);

	uint16_t val ;
	uint16_t lastval=0 ;
	uint32_t percent ;
	uint32_t full ;
	uint8_t i ;
	while (1)
	{
		val = ADC_Read();
		if(val !=lastval)
		{
			LCD_gotoxy(1,0);
			LCD_WRITE_STRING("sound = ");
			percent = (((uint32_t)val*100)/1024);
			
			lcd_WRITE_NUM(percent);
			LCD_gotoxy(2,0);
			full = percent/5 ;
			for(i=0 ; i < full ;i++)
			{
				LCD_WRITE_CHAR(0xff);
				
			}
			lastval=val ;
			LCD_WRITE_STRING("            ");
			
		}
	
		
		
		
	  }
		 
	return 0; 
}
