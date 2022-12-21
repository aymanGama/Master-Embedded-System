/*
 * Uart.h
 *
 * Created: 11/20/2022 5:02:47 PM
 *  Author: DR-Mosaad
 */ 


#ifndef UART_H_
#define UART_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "MemMap.h"
#define DefaultEnter  '\r'

//API
void UART_Init(void);
void UART_Transmit(uint8_t data);
uint8_t UART_Resive(void);
void UART_Transmit_intnum(uint32_t data);
void UART_Transmit_String(uint8_t* data);
void UART_Recive_String(uint8_t* data);
uint8_t UART_Resive_periodic_check(uint8_t* chartact);
#endif /* UART_H_ */