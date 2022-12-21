/*
 * SPI.c
 *
 * Created: 11/25/2022 5:13:14 PM
 *  Author: Ayman Gamal
 */ 
#include "avr/io.h"
#include "SPI.h"
void SPI_MASTER_INIT (void)
{
	/*
	Bit 4 – MSTR: Master/Slave Select
	This bit selects Master SPI mode when written to one, and Slave SPI mode when written
	logic zero.
	*/
	Setbit(SPCR, MSTR);
	
  DDRB = ((1<<5)| (1<<7)|(1<<4));
//	Bit 6 – SPE: SPI Enable
//  When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable
//	any SPI operations.
	Setbit(SPCR ,SPE);
}
uint8_t SPI_MASTER_TR_RE (uint8_t data)
{
	
	SPDR = data ;
	/*Bit 7 – SPIF: SPI Interrupt Flag
	When a serial transfer is complete, the SPIF Flag is set.
	*/
	while (!(Readbit(SPSR,SPIF)));
	return SPDR ;
	
}
 
