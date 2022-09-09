/*
 * fifo.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Ayman_Gamal
 */


#ifndef FIFO_H_
#define FIFO_H_
#include "stdint.h"
#include "stdio.h"
#define width  5
typedef  uint8_t element_type ;

element_type UART_buf [width];
//  fifo type definitions

typedef struct {
    unsigned int length ;
	unsigned int count ;
	element_type* head ;  // it is point to address it will enqueue in it
	element_type* base ;  // it is Base  address we assign head and tail to it when its reach to last address
	element_type* tail ;  // it is point to address it will dequeue form it
}FIFO_BUFF_t;
typedef enum {
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null,
}fifo_status;


//    fifo APIS
fifo_status FIFO_init (FIFO_BUFF_t* fifo ,element_type* buf , unsigned int  length); //initialize queue
fifo_status FIFO_enqueue (FIFO_BUFF_t* fifo ,element_type item);   //function add items to queue
fifo_status FIFO_dequeue (FIFO_BUFF_t* fifo ,element_type* item);  //function get items from queue
fifo_status FIFO_IS_full (FIFO_BUFF_t* fifo );   //function check if queue is full
void PRINT_buf (FIFO_BUFF_t* fifo); //function print our queue

#endif /* FIFO_H_ */
