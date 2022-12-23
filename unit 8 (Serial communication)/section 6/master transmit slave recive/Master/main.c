/*
 * master.c
 *
 * Created: 11/28/2022 4:00:21 PM
 * Author : Ayman Gamal
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"
int main(void)
{
	unsigned char ch=0;
	I2C_Init(0x48);
	while (1)
	{
		_delay_ms(500);
		I2C_Start();                    //Trasmit Start Condition
		I2C_Write(0b11010000+0);       //Transmit  SLA + W(0)
		while ((TWSR) != 0x18);       //SLA + W(0) has been transmitted and ACK has been Received
		I2C_Write(ch++);             // Transmit Data
		while ((TWSR) != 0x28);     //Data has been transmitted and ACK has been Received
		I2C_Stop();                //Transmit Stop condition
	}
}


