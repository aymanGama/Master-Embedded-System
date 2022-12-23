/*
 * I2C.h
 *
 * Created: 28/11/2022 3:51:10 AM
 *  Author:  ayman
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char cByte);
unsigned char I2C_Read(unsigned char ack);
void I2C_Stop();



#endif /* I2C_H_ */