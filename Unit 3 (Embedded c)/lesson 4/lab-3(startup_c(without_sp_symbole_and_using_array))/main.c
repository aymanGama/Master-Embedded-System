//lab-3(startup_c(without_sp_symbole_and_using_array)) 
// ENG:Ayman_Gamal
#include <stdint.h>

#define  SYSCTL_RCGC2_R    *((volatile unsigned long*)(0x400FE108))
#define  GPIO_PORTF_DATA_R    *((volatile unsigned long*)(0X400253FC))
#define  GPIO_PORTF_DIR_R    *((volatile unsigned long*)(0X400253400))
#define  GPIO_PORTF_DEN_R    *((volatile unsigned long*)(0X4002551C))


void main(){
volatile unsigned long i;
SYSCTL_RCGC2_R=0x20;
GPIO_PORTF_DIR_R |=1<<3;
GPIO_PORTF_DEN_R |=1<<3;
	
	while(1){
		GPIO_PORTF_DATA_R |=1<<3;
		for(i=0;i<20000;i++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(i=0;i<20000;i++);
	}
}
