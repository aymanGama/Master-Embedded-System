//lab-3(startup_c(without_sp_symbole_and_using_array_of_pointers_to_functions)) 
// ENG:Ayman_Gamal
#include <stdint.h>

#define  SYSCTL_RCGC2_R    (*((volatile unsigned long*)0x400FE108))
#define  GPIO_PORTF_DATA_R    (*((volatile unsigned long*)0x400253FC))
#define  GPIO_PORTF_DIR_R    (*((volatile unsigned long*)0x40025400))
#define  GPIO_PORTF_DEN_R    (*((volatile unsigned long*)0x4002551C))


int main()
{
volatile unsigned long i;
SYSCTL_RCGC2_R= 0x00000020;
for(i=0;i<2000;i++);
GPIO_PORTF_DIR_R |= 1<<3;
GPIO_PORTF_DEN_R |= 1<<3;
	
	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for(i=0;i<20000;i++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(i=0;i<20000;i++);
	}
  return 0 ;
}
