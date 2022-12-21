/*
 * SPI.c
 *
 * Created: 11/25/2022 5:13:14 PM
 *  Author: Ayman gamal 
 */ 
#include "avr/io.h"
#include "SPI.h"
void SPI_SLAVE_INIT (void)
{
	/*
	Bit 4 – MSTR: Master/Slave Select
	This bit selects Master SPI mode when written to one, and Slave SPI mode when written
	logic zero.
	*/
	Clearbit(SPCR, MSTR);
//set MISO as output and other pins are input 
     DDRB = (1<<6) ; 
	

//	Bit 6 – SPE: SPI Enable
//  When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable
//	any SPI operations.
	Setbit(SPCR ,SPE);
}
uint8_t SPI_SLAVE_TR_RE (uint8_t data)
{
	SPDR = data ;
	/*Bit 7 – SPIF: SPI Interrupt Flag
	When a serial transfer is complete, the SPIF Flag is set.
	*/
	while (!(Readbit(SPSR,SPIF)));
	return SPDR ;
	
}
 
