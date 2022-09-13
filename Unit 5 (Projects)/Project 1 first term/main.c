#include "mainalg.h"
#include "alarmmonitor.h"

void setup()
{
	P_mainalg=algwaiting;
	P_alarmmonitor=alarmOff;

}
int main (){
	GPIO_INITIALIZATION();
	alarminit ();
	setup();
	while (1)
	{
		algwaiting();
		P_mainalg();
		P_alarmmonitor();
		Delay(400000);
		//Implement your Design 
	}

}
