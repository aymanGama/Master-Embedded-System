/*
 * MemMap.h
 *
 * Created: 11/20/2022 5:00:51 PM
 *  Author: DR-Mosaad
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define Setbit(reg,bit)    (reg |= (1<<bit))
#define Clearbit(reg,bit)    (reg &= ~(1<<bit))
#define Readbit(reg,bit)    ((reg & (1<<bit))>>bit)

/*
#define PORTD  *((volatile unsigned char *)(0x32))
#define DDRD   *((volatile unsigned char *)(0x31))
#define PIND   *((volatile unsigned char *)(0x30))
//Addresses for I/O PORTA (port A is output with Vcc in all pins)
#define PORTA  *((volatile unsigned char *)(0x3B))
#define DDRA   *((volatile unsigned char *)(0x3A))
#define PINA   *((volatile unsigned char *)(0x39))

*/


#endif /* MEMMAP_H_ */