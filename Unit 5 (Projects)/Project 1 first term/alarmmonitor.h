#ifndef ALARMMONITOR_H
#define ALARMMONITOR_H
#include "driver.h"
void alarminit ();
void alarmOn();
void alarmOff();
void set_alarm();
extern void (*P_alarmmonitor)();

#endif  /* ALARMMONITOR_H */
