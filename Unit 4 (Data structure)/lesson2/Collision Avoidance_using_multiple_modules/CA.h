/*
 * CA.h
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
extern void (*P_CA_state)();
// define state
enum {
	CA_waiting ,
	CA_driving
}CA_state;
// declare state function
state_define(waiting);
state_define(driving);



#endif /* CA_H_ */
