/*
 * memmap.h
 *
 * Created: 10/24/2022 12:10:00 AM
 *  Author: Eng.Ayman
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "utilits.h"
#define F_CPU 8000000UL
//addresses for I/O PORTD (port D is input in pin0 it is internal is pull up )
#define PORTD  *((volatile unsigned char *)(0x32))
#define DDRD   *((volatile unsigned char *)(0x31))
#define PIND   *((volatile unsigned char *)(0x30))
//Addresses for I/O PORTA (port A is output with Vcc in all pins)
#define PORTA  *((volatile unsigned char *)(0x3B))
#define DDRA   *((volatile unsigned char *)(0x3A))
#define PINA   *((volatile unsigned char *)(0x39))


#endif /* MEMMAP_H_ */