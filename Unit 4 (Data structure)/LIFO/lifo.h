/*  LIFO stack first input first out but we make array and make structure
 *  contain 2 pointers rto point to element in array
 *  and length_value: to know number of element use it to check if buffer empty
 *  and counter to count and know us number of element after any process
 * lifo.h
 *
 *  Created on: Sep 1, 2022
 *      Author:Ayman_Gamal
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdint.h"
#define width  5
typedef uint8_t element_unit  ;
//type definitions
typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_unit * Base ;  //base address
	element_unit * Head ; //point to element in stack to add or get
}LIFO_BUF_t ;
typedef enum {
	LIFO_no_error ,
	LIFO_null ,
	LIFO_full ,
	LIFO_empty
}LIFO_STATUS;


//APIS
LIFO_STATUS LIFO_Add_Buf (LIFO_BUF_t* P_BUF , element_unit item);
LIFO_STATUS LIFO_get_Buf (LIFO_BUF_t* P_BUF , element_unit* item);
LIFO_STATUS LIFO_init (LIFO_BUF_t* P_BUF , element_unit* buf ,unsigned int length);
void Print_LIFo (LIFO_BUF_t* P_BUF);
#endif /* LIFO_H_ */
