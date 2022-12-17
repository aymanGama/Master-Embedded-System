/*
 * LAB 1 (3) LEDS.c
 *
 * Created: 10/24/2022 11:15:01 PM
 * Author : Ayman Gamal 
 */ 
#define F_CPU 8000000UL

#include "memmap.h"

int main(void)
{
	//make PINS 0,1,2 in PORTD AS INPUT 
    Clearbit(DDRD,0);
	Clearbit(DDRD,1);
	Clearbit(DDRD,2);
	Setbit(PORTD,0)  ;
	Setbit(PORTD,1)  ;
	Setbit(PORTD,2)  ;
	
	//MAKE PINS 4,5,6,7 PORTD as output 
	Setbit(DDRD,4)  ;
	Setbit(DDRD,5)  ;
	Setbit(DDRD,6)  ;
	Setbit(DDRD,7)  ;
	volatile unsigned char i=0,x=0,y=7 ;
    while (1) 
    {
		if (Readbit(PIND,0) == 1)          // if pressing on push button(0) three led are started to fire one by one the time between them is 0.5s  
		{
			for (i=5;i<8;i++)
			{
				Setbit(PORTD,i) ;
				_delay_ms(500) ;
			}
			i-=1;
		}
		 
		while (i)                          // after pressing push button(0) and three led fire its started to power off one bye one time 0.5s
		{ 
			Clearbit(PORTD,(i));       
			_delay_ms(500);
			i-- ;
		}
		if (Readbit(PIND,1) == 1)          // if pressing on push button(1) three led are started to fire one by one for every press on push button and after all leds is fire if i press it will power of all leds
		{
			switch (x)
			{
				case 0:
				{
					Setbit(PORTD,5);                        // fire first led
					x=1;
					while(Readbit(PIND,1) == 1);
					break;
				}
				case 1:                                     // fire second led
				{
					Setbit(PORTD,6);
					x=2;
					while(Readbit(PIND,1) == 1);
					break;
				}
				case 2:                                     // fire third led
				{
					Setbit(PORTD,7);
					x=3;
					while(Readbit(PIND,1) == 1);
					break;
				}
				case 3:                                     //power off 
				{
						while(y>4)
						{
							Clearbit(PORTD,y);
							y--;
						}
						while(Readbit(PIND,1) == 1);
						y=7;
						x=0;
						break;
				}
				default:
				{
					break;
				}
			}
				
		}
		
		if (Readbit(PIND,2) == 1)
		{
			Setbit(PORTD,4);
			while(Readbit(PIND,2) == 1);
			Clearbit(PORTD,4);
		}
		
		
	}
		
}

