/*
 * US.c
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */
#include "US.h"
//define variable

int US_distance=0;


extern void (*P_US_state)();

state_define(US_init)
{
	printf("US_sensor init \n");
}
state_define(US_busy)
{
	//init state
	US_state =US_state_busy ;
	// define speed
	//get distance from sensor and sent it to collision avoidence
	US_distance=generate_random_distance(45,55,1);
	printf("US sensor -----distance=%d-------->CA \n",US_distance);
	get_distance(US_distance);
	P_US_state=state(US_busy);

}

int generate_random_distance(int a ,int r,int count)
{
	// it will generate random number between a and r
	int i;
	for (i=0;i<count;i++)
	{
		int randum_number =(rand()%(r-a+1))+a;
		return randum_number;
	}

}


