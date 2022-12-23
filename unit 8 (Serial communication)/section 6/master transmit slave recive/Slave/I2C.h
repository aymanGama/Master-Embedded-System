/*
 * I2C.h
 *
 * Created: 11/28/2022 4:02:22 PM
 *  Author: Ayman Gamal
 */ 


#ifndef I2C_H_
#define I2C_H_
#define F_CPU 16000000UL

#include "avr/io.h"

void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(void);


#endif /* I2C_H_ */