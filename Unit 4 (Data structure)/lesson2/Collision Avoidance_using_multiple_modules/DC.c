/*
 * DC.c
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */
#include "DC.h"
//define variable
int DC_speed=0;
void send_speed (int s)
{
	DC_speed=s;
	P_DC_state=state(busy);
	printf("CA-------------speed=%d------->DC_motor\n",DC_speed);

}
state_define(DC_init)
{
	printf("DC motor init \n");
}


state_define(idle)
{
	//init state
	DC_state =DC_state_idle ;

	P_DC_state=state(idle);

}
state_define(busy)
{
     	//state Name
		DC_state =DC_state_busy ;
		P_DC_state=state(busy);

}

void (*P_DC_state)();
