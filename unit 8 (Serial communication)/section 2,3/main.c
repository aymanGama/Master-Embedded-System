/*
 * UART_Driver.c
 *
 * Created: 11/20/2022 4:56:37 PM
 * Author : DR-Mosaad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>

#include "MemMap.h"
#include "lcd.h"
#include "Uart.h"
uint8_t  cahracter;
int main(void)
{
	char data[100] ;
   LCD_init();
   UART_Init();
  // UART_Transmit('a');
   UART_Transmit_String("alaa");
   //UART_Transmit_intnum(300);
   LCD_WRITE_CHAR('a');
   UART_Recive_String (data);
   LCD_WRITE_STRING(data);
   LCD_clear_screen();
    while (1) 
    {
		

		if(UART_Resive_periodic_check(&cahracter))
		{
			LCD_gotoxy(1,0);
			LCD_WRITE_CHAR(cahracter);
			
		}
		
		//_delay_ms(10);
    }
}

