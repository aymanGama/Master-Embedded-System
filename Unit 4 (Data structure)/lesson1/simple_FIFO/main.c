/*
 * main.c
 *
 *  Created on: Sep 4, 2022
 *      Author: Ayman_Gamal
 */
#include "stdio.h"
#include "stdlib.h"
#define width 5
#define APRINT(...)                                {fflush(stdin); \
													 fflush(stdout); \
													 printf(__VA_ARGS__);}
typedef struct {
	int arr[width];
	int temp ;
	int var ;
	int count ;
}Sstruct_t;

void check_init (Sstruct_t * s)
{
	if(s->temp == -1 )
	{
		APRINT ("\n initialize====Done=== ")
		s->temp = 0 ;
	}
}

int check_full(Sstruct_t* s)
{
	if (s->var == width)
	{
		APRINT  ("\n it is full")
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}
int check_empty (Sstruct_t* s)
{
	if (s->var == 0)
	{
		APRINT ("\n it is empty")
		return 1 ;
	}
	else
		return 0;
}
void add_element (Sstruct_t* s , int value_of_element )
{
	APRINT ("\n add %d",value_of_element)
	if(check_full(s) == 1)
		APRINT ("\n you cannot add it")
	else
	{
		if (s->count ==width)
		{
			s->count =0 ;
		}
		if (s->temp ==width)
		{
			s->temp =0 ;
		}

		s->arr[s->temp] = value_of_element ;
		s->temp++ ;
		s->var++ ;

	}

}
void get_element (Sstruct_t* s )
{
	APRINT ("\n get element ")
	if(check_empty( s) == 1)
		APRINT ("\n you cannot get it ")
	else
	{
		if (s->count ==width)
		{
			s->count =0 ;
		}
		s->count++ ;
		s->var-- ;

	}
}
void PRINT(Sstruct_t*s)
{
	APRINT("\n your stack is : ")
	if(s->var==0)
		APRINT("\n \t Empty")
	else
	{
		int i ;
		for(i=s->count ; i<s->temp ;i++)
		{
			APRINT("\n \t %d",s->arr[i])
		}
	}

}
void main()
{
	Sstruct_t x ;
	x.temp=-1 ;
	x.var=0;
	x.count=0;
	check_init(&x);
	add_element(&x , 1);
	add_element(&x , 2);
	add_element(&x , 3);
	add_element(&x , 4);
	add_element(&x , 5);
	PRINT(&x);
	add_element(&x , 6);
	PRINT(&x);
	add_element(&x , 7);
	PRINT(&x);
	get_element(&x);
	get_element(&x);
	PRINT(&x);
	get_element(&x);
	get_element(&x);
	get_element(&x);
	PRINT(&x);
	get_element(&x);
	PRINT(&x);
	add_element(&x , 1);
	add_element(&x , 2);
	PRINT(&x);
	get_element(&x);
	PRINT(&x);
}






