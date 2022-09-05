/*
 * main.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Ayman_Gamal
 */
#include "lifo.h"

element_unit arr_buf [width];

void main ()
{
	element_unit i , item=0;
	LIFO_BUF_t first_buf ;
	if((LIFO_init(&first_buf ,arr_buf,width))==LIFO_no_error)
		printf("\nLIFO initialize=====DONE======\n");

	for(i=0; i<4;i++)
	{
	if(	LIFO_Add_Buf(&first_buf, i) == LIFO_no_error)
		printf("lifo add: %d\n",i);
	else if (	LIFO_Add_Buf(&first_buf, i) == LIFO_full)
			printf("lifo is full \n");
	}
	Print_LIFo(&first_buf);
	for(i=0; i<7;i++)
	{	if(	LIFO_get_Buf(&first_buf, &item) == LIFO_no_error)
			printf("lifo get: %d\n",item);
	else if(	LIFO_get_Buf(&first_buf, &item) == LIFO_empty)
				printf("lifo is empty \n");
	}
	Print_LIFo(&first_buf);

	for(i=0; i<6;i++)
	{
	if(	LIFO_Add_Buf(&first_buf, i) == LIFO_no_error)
		printf("lifo add: %d\n",i);
	else if (	LIFO_Add_Buf(&first_buf, i) == LIFO_full)
			printf("lifo is full \n");
	}
	Print_LIFo(&first_buf);
	for(i=0; i<3;i++)
		{	if(	LIFO_get_Buf(&first_buf, &item) == LIFO_no_error)
				printf("lifo get: %d\n",item);
		else if(	LIFO_get_Buf(&first_buf, &item) == LIFO_empty)
				printf("lifo empty \n");
		}

		Print_LIFo(&first_buf);
}

