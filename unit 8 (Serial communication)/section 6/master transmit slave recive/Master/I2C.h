/*
 * I2C.h
 *
 * Created: 11/28/2022 4:02:22 PM
 *  Author: DR-Mosaad
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "avr/io.h"
#define prescaler    1
void I2C_Init (unsigned long SCL_freq);
void I2C_Start(void);
void I2C_Write(unsigned char data);
void I2C_Stop(void);




#endif /* I2C_H_ */