/*
 * CA.c
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */
#include "CA.h"
//define variable
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;


void get_distance (int d)
{
	CA_distance=d;
	(CA_distance<=CA_threshold) ? (P_CA_state=state(waiting)) : (P_CA_state=state(driving));


}

state_define(waiting)
{
	//init state
	CA_state = CA_waiting ;
	 printf(" CA waiting state:  distance=%d  speed=%d \n",CA_distance,CA_speed);
	// define speed
	CA_speed=0;
	//send speed to dc motor
	send_speed(CA_speed);



}
state_define(driving)
{
     	//state Name
		CA_state = CA_waiting ;
		 printf("CA driving state: distance=%d  speed=%d\n",CA_distance,CA_speed);
		// state action  set speed = 0
		CA_speed=30;
		//send speed to dc motor
		send_speed(CA_speed);
		// check distance and get state


}

void (*P_CA_state)();
