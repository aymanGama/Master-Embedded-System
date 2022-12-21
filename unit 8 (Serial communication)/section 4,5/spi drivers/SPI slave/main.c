/*
 * SPIslave.c
 *
 * Created: 11/25/2022 5:12:30 PM
 * Author : Ayman Gamal
 */ 
#define  F_CPU 1000000UL

#include <avr/io.h>
#include "util/delay.h"
#include "SPI/SPI.h"




int main(void)
{
	SPI_SLAVE_INIT();
    /* Replace with your application code */
	DDRA = 0xff ;
    uint8_t data ;
	for (data=0 ; data<200; data++) 
    {
		_delay_ms(100);
		PORTA = SPI_SLAVE_TR_RE(data);
    }
}

