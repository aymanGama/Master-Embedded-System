/*
 * Uart.c
 *
 * Created: 11/20/2022 5:02:30 PM
 *  Author: DR-Mosaad
 */ 
#include "Uart.h"


void UART_Init(void)
{
	//***Baud rate 
	UBRRL =51 ;
	// normal mode not double speed 
	Clearbit(UCSRA,U2X);
	//Asynchronous 
	Clearbit(UCSRC,UMSEL);
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_

	//***frame 
	//parity disabled by default at register (UCSRC) UPM1=0 UPM0=0
	// one stop bit by default at register (UCSRC) USBS=0
	//8Bit data
	UCSRC |= (3<<UCSZ0);
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
	//***Enable 
	// Enable TX,RX
	Setbit(UCSRB,TXEN);
	Setbit(UCSRB,RXEN);
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_

}
	
void UART_Transmit(uint8_t data)
{
	//The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. 
	//if UDRE is one, the buffer is empty, and therefore ready to be written.
    while(!Readbit(UCSRA,UDRE));
	UDR =data ;
	
}
uint8_t UART_Resive(void)
{
	uint8_t data ;
	//This flag bit is set when there are unread data in the receive buffer and cleared
	//when the receive buffer is empty
	while (! Readbit(UCSRA,RXC));
	data = UDR  ;
	return data;
}

uint8_t UART_Resive_periodic_check(uint8_t* chartact)
{
	
	if ( Readbit(UCSRA,RXC))
	{
		*chartact =UDR ;
		return 1;
	
	}
	return 0;
}
/*
void UART_Transmit_intnum(uint32_t data)
{
	uint8_t*p = &data ;
	UART_Transmit(p[3]);
	UART_Transmit(p[2]);
	UART_Transmit(p[1]);
	UART_Transmit(p[0]);
}
*/
void UART_Transmit_String(uint8_t* data)
{
	uint8_t  i ;
	for (i=0 ; i<data[i];i++)
	{
		UART_Transmit(data[i]);
		
	}
	
	UART_Transmit(DefaultEnter);
}
void UART_Recive_String(uint8_t* data)
{
	uint8_t  i =0 ;
	data[i] = UART_Resive();  //maybe the value in data0 is = Default enter 
	while (data[i] != DefaultEnter)
	{
		i++ ;
		data[i] =UART_Resive();
		
	}
	
	data[i] ='\0';
}
