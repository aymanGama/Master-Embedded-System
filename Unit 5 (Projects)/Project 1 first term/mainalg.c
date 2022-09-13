#include "mainalg.h"
void (*P_mainalg)();
int Pval=0; int threshold=20;
void algwaiting()
{
	Pval=getPressureVal();
	(Pval>=threshold) ? (P_mainalg=HighPressureDetection) : (P_mainalg=algwaiting);
	
}
void HighPressureDetection()
{
	set_alarm();

}
