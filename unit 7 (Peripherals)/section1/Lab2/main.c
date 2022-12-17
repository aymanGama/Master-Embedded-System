/*
 * LAB1.c
 *
 * Created: 10/24/2022 12:00:56 AM
 * Author : Eng.Ayman
 */ 

#include "memmap.h"

#include <util/delay.h>

int main(void)
{
	// set PORTD IS INPUT  AND A output 
	volatile unsigned char Button ; 
	DDRA =0b11111111  ;
	Clearbit(DDRD,0)  ;
	Setbit(PORTD,0)   ;
   
    while (1) 
    {
		if(Readbit(PIND ,0) ==0)
		{
		
			for(Button=0;Button<8;Button++)
			{
				Setbit(PORTA,Button);
				_delay_ms(500);
			}
			
		}
		
		while(Button)
		{
			Button--;
			Clearbit(PORTA,Button) ;
			_delay_ms(500);
		}
		
		
    }
	return 0 ;
}

