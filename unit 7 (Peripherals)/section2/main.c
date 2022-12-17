/*
 * LCDandKEYPAD.c
 *
 * Created: 10/29/2022 12:20:20 PM
 * Author : Ayman
 */ 

#define F_CPU 8000000UL

#include "LCD/lcd.h"
#include "KEYPAD/KEYPAD.h"

 


int main(void)
{
	 LCD_init();
	KEYBAD_INIT() ;
	char presskey ;
    /* Replace with your application code */
    while (1) 
    {
		presskey = KEYPAD_GET_CHAR();
		switch (presskey)
		{
			case '?':
			{
				LCD_clear_screen();
				break ;
			}
			case 'N':
			{
				break ;
			}
			default:
			{
				LCD_WRITE_CHAR(presskey);
				break;
			}
			
         }
	
     }
}

