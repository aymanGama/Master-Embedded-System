/*
 * I2C.c
 *
 * Created: 11/28/2022 4:02:02 PM
 *  Author: Ayman Gamal
 */ 
#include "I2C.h"
#define F_CPU 16000000UL

void I2C_Init (unsigned long SCL_freq)
{
	TWBR =(((F_CPU/SCL_freq)-16)/(2*prescaler));   //set clock from master I2C
	if (prescaler==1)
	{
		TWSR=0;
	}
	else if (prescaler==4)
	{
		TWSR=1;
	}
	else if (prescaler==16)
	{
		TWSR=2;
	}
	if (prescaler==64)
	{
		TWSR=3;
	}
}
void I2C_Start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);  //Send START condition
	while (((TWCR &(1<<TWINT))==0));              //Wait for TWINT Flag set. This indicates that the START condition has been transmitted
	while ((TWSR)!=0x08);                  //A START condition has been transmitted
	
}
void I2C_Write(unsigned char data)
{
	TWDR = data;                               //Load SLA_W into TWDR Register. ClearTWINT bit in TWCR to start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);                  //set flag 
	while ((TWCR & (1<<TWINT))==0);              ///wait to finish
}
void I2C_Stop(void)
{
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);    //transmit stop condition
}