/*
 * salve.c
 *
 * Created: 11/28/2022 4:01:32 PM
 * Author : Ayman Gamal
 */ 

#define F_CPU 16000000UL

#include "I2C.h"
#include <avr/io.h>


int main(void)
{
	DDRA=0xFF;
	I2C_Set_Address(0b11010000);         //Enable slave at address 01101000 and Don't accept general call
	while (1)
	{
		PORTA = I2C_Read();             // Receive Byte and send ACK
	}
	return 0;
}

