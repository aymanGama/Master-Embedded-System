/*
 * US.h
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */

#ifndef US_H_
#define US_H_

#include "state.h"
void (*P_US_state)();
int generate_random_distance(int a ,int r,int count);
// define state
enum {
	US_state_busy,
}US_state;
// declare state function
state_define(US_busy);
state_define(US_init);



#endif /* US_H_ */
