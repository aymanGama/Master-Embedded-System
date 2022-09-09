/*
 * state.h
 *
 *  Created on: Sep 7, 2022
 *      Author: DR-Mosaad
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"


#define state_define(st_function)  void ST_##st_function()
#define state(st_function) ST_##st_function

//state connection
void get_distance (int d);
void send_speed (int s);

#endif /* STATE_H_ */
