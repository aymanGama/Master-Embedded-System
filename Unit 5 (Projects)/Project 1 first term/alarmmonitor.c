#include "alarmmonitor.h"
void set_alarm()
{
	P_alarmmonitor=alarmOn ;
}

void alarminit ()
{

	Set_Alarm_actuator(1);
}
void alarmOff()
{
	Set_Alarm_actuator(1);
}
void alarmOn()
{
	Set_Alarm_actuator(0);
	Delay(600000);
	Set_Alarm_actuator(1);
	P_alarmmonitor=alarmOff;
}
 void (*P_alarmmonitor)();
