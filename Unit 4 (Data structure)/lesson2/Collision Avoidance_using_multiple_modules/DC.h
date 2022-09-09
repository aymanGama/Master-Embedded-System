/*
 * DC.h
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
extern void (*P_DC_state)();
// define state
enum {
	DC_state_idle,
	DC_state_busy
}DC_state;
// declare state function
state_define(idle);
state_define(busy);
state_define(DC_init);



#endif /* DC_H_ */
