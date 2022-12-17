/*
 * prototype1.h
 *
 * Created: 10/24/2022 11:17:33 PM
 *  Author: Ayman_ Gamal 
 */ 



#ifndef PROTOTYPE1_H_
#define PROTOTYPE1_H_
#include "utilits.h"
#include <util/delay.h>
//addresses for I/O PORTD (port D is input in pin0 it is internal is pull up )
#define PORTD  *((volatile unsigned char *)(0x32))
#define DDRD   *((volatile unsigned char *)(0x31))
#define PIND   *((volatile unsigned char *)(0x30))
//Addresses for I/O PORTA (port A is output with Vcc in all pins)
#define PORTA  *((volatile unsigned char *)(0x3B))
#define DDRA   *((volatile unsigned char *)(0x3A))
#define PINA   *((volatile unsigned char *)(0x39))






#endif /* PROTOTYPE1_H_ */