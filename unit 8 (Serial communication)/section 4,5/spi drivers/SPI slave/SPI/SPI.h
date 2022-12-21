/*
 * SPI.h
 *
 * Created: 11/25/2022 5:13:29 PM
 *  Author: Ayman Gamal 
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "avr/io.h"

#define Setbit(reg,bit)    (reg |= (1<<bit))
#define Clearbit(reg,bit)    (reg &= ~(1<<bit))
#define Readbit(reg,bit)    ((reg & (1<<bit))>>bit)

void SPI_SLAVE_INIT (void);
uint8_t SPI_SLAVE_TR_RE (uint8_t data);




#endif /* SPI_H_ */