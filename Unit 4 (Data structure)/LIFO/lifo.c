/*
 * lifo.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Ayman_Gamal
 */

#include "lifo.h"

LIFO_STATUS LIFO_Add_Buf (LIFO_BUF_t* P_BUF , element_unit item)
{
	// if valid

	if (!P_BUF->Base||!P_BUF->Head)
		return LIFO_null;
	//if full
	if(P_BUF->count==P_BUF->length)
		return LIFO_full;
	//add value
	*(P_BUF->Head)=item;
	P_BUF->Head++;
	P_BUF->count++;
	return LIFO_no_error;

}

LIFO_STATUS LIFO_get_Buf (LIFO_BUF_t* P_BUF , element_unit* item)
{   // if valid

	if (!P_BUF->Base||!P_BUF->Head)
		return LIFO_null;
	//if empty
	if(P_BUF->count == 0)
		return LIFO_empty;
	//get value
	P_BUF->Head--;
	*item=*(P_BUF->Head);
	P_BUF->count--;
	return LIFO_no_error;
}

LIFO_STATUS LIFO_init (LIFO_BUF_t* P_BUF , element_unit* buf ,unsigned int length)
{

	if( buf == NULL )
		return LIFO_null;
	P_BUF->Base=buf;
	P_BUF->Head=buf;
	P_BUF->length  =length;
	P_BUF->count=0;
	return LIFO_no_error;
}
void Print_LIFo (LIFO_BUF_t* P_BUF)
{
	element_unit* temp = (element_unit*)P_BUF->Base;
	printf("\n====BUFFER_NOW=====\n");
	int i ;
	//check init validation
	if (!P_BUF->Base||!P_BUF->Head)
		printf ("\n error at initialization");
	else
	{
		if (P_BUF->count==0)
			printf(" *Buffer is Empty* \n");
		else
		{
			for(i=0; i<P_BUF->count ;i++)
			{
				printf("\t %d \n",*temp);
				temp++;

			}
		}

	}

}
