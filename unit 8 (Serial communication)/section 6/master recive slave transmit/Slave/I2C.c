/*
 * I2C.c
 *
* Created: 28/11/2022 4:29:10 AM
 *  Author:  ayman
 */ 
#include "I2C.h"

void I2C_Set_Address(unsigned char address)
{
	TWAR = address;
}
unsigned char I2C_Read(unsigned char ack)
{
	unsigned char x=0;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 0x80) == 0);
	
}
void I2C_Write(unsigned char cByte)
{
	TWDR = cByte;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & 0x80)==0);
}