/*
 * main.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Ayman_Gamal
 */
#include "fifo.h"
void main(){

	FIFO_BUFF_t Fifo_s ;
	element_type i , item=0;
	if (FIFO_init (&Fifo_s ,&UART_buf, 5) ==  fifo_no_error)
		printf("\t fifo init is =====DONE=====\n");


	for (i=0 ;i<7 ; i++)
	{
		if(FIFO_enqueue(&Fifo_s,i)==fifo_no_error)
			printf("\t fifo enqueue %x =======Done=====\n",i);
		else
			printf("\t fifo enqueue %x =======failed=====\n",i);
	}
	PRINT_buf(&Fifo_s);

	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
	{
		printf("\t fifo dequeue==Falid===fifo is empty \n");
	}

	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
		{
			printf("\t fifo dequeue==Falid===fifo is empty \n");
		}

	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
		{
			printf("\t fifo dequeue==Falid===fifo is empty \n");
		}

	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
		{
			printf("\t fifo dequeue==Falid===fifo is empty \n");
		}


	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
		{
			printf("\t fifo dequeue==Falid===fifo is empty \n");
		}

	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
		{
			printf("\t fifo dequeue==Falid===fifo is empty \n");
		}


	PRINT_buf(&Fifo_s);
	if(FIFO_dequeue( &Fifo_s,&item) == fifo_no_error)
		printf("\t fifo dequeue %x ====Done=====\n",item);
	else
		{
			printf("\t fifo dequeue==Falid===fifo is empty \n");
		}

	PRINT_buf(&Fifo_s);
	if(FIFO_enqueue(&Fifo_s,4)==fifo_no_error)
		printf("\t fifo enqueue %x =======Done=====\n",4);
	else
		printf("\t fifo enqueue %x =======failed=====\n",4);
	PRINT_buf(&Fifo_s);
}

