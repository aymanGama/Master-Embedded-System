/*
 * I2C.c
 *
 * Created: 11/28/2022 4:02:02 PM
 *  Author: Ayman_gamal
 */ 
#include "I2C.h"
void I2C_Set_Address(unsigned char address)
{
	TWAR = address;
}
unsigned char I2C_Read(void)
{

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 1<<7) == 0);
	while ((TWSR) != 0x60);             // own SLA+W(0) has been transmitted and ACK has been returned
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 1<<7) == 0);
	while ((TWSR) != 0x80);          // Data has been transmitted and ACK has been returned
	return TWDR;

}