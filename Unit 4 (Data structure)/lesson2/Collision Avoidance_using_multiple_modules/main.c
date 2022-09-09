/*
 * main.c
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//set init
	state(US_init)();
	state(DC_init)();
	//set pointer for states
	P_CA_state=state(waiting);
	P_DC_state=state(idle);
	P_US_state=state(US_busy);
}
void main()
{
	volatile int x;
	setup();
	while(1)
	{
		//call state for each block
		P_US_state();
		P_CA_state();
		P_DC_state();


		for(x=0;x<100000;x++);

	}

}
