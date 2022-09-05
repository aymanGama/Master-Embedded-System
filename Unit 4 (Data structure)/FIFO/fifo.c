/*
 * fifo.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Ayman_Gamal
 */
#include "fifo.h"


fifo_status FIFO_init (FIFO_BUFF_t* fifo ,element_type* buf ,unsigned int length){
	// check init validation
	if (!buf || !fifo)
		return fifo_null ;
	//assign  three addresses to Uart_BUffer array
	fifo->base = buf ;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0 ;        // it is count number of element  in UART_BUffer
	return fifo_no_error ;
}

fifo_status FIFO_enqueue (FIFO_BUFF_t* fifo ,element_type item)
{
	// check init validation
	if (!fifo->tail || !fifo->head ||!fifo->base)
		return fifo_null ;
	// check buff===full
	if( FIFO_IS_full ( fifo )== fifo_full )
		return fifo_full;
	*(fifo->head) = item ;  // enqueue item in Uart_BUffer
	fifo->count++;          // increase count by 1
	//check if head reach to last element in UART_BUffer in next step return it to first address of array
	if (fifo->head == fifo->base +(fifo->length * sizeof(element_type)))
		fifo->head = fifo->base;
	else
		fifo->head++;
	return fifo_no_error;

}

fifo_status FIFO_dequeue (FIFO_BUFF_t* fifo ,element_type* item){
	// check init validation
	if (!fifo->tail || !fifo->head ||!fifo->base)
		return fifo_null ;
	//check buf empty
	if( fifo->count == 0)
		return fifo_empty;
	*item =*(fifo->tail);
	fifo->count--;
	//check if tail reach to final address return it to base address
	if (fifo->tail == fifo->base +(fifo->length * sizeof(element_type)))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return fifo_no_error;

}
fifo_status FIFO_IS_full (FIFO_BUFF_t* fifo ){
	if (!fifo->tail || !fifo->head ||!fifo->base)
		return fifo_null ;

	if(fifo->count==fifo->length)
		return fifo_full;
	return fifo_no_error;
}
void PRINT_buf (FIFO_BUFF_t* fifo){
	element_type i;
	element_type* temp = (element_type*)fifo->tail; //temp pointer point to tail address i dequeue from it
	printf("=======BUFFER NOW=====\n");
	if (fifo->count==0)
		printf("Buffer is Empty \n");
	for(i=0;i<fifo->count;i++){
		printf("buffer element %x \n",*temp);
		temp++;
	}
}
