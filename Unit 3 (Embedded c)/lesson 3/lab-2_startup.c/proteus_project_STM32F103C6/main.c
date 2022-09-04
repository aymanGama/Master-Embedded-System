//LAB-2 
// ENG:Ayman_Gamal
#include <stdint.h>
#define  RCC_BASE    (0x40021000)
#define  GPIO_BASE   (0x40010800)
#define  APP2ENR    *((volatile uint32_t*)(RCC_BASE+0x18))
#define  GPIO_CRH    *((volatile uint32_t*)(GPIO_BASE+0x04))
typedef volatile unsigned int vuint_t ;
typedef union{
	vuint_t    all_field;
	struct {
		vuint_t first_bins:13 ;
		vuint_t p_13:1 ;
	} S_ODR;
}U_ODR_t;
volatile U_ODR_t* P_ODR=(volatile U_ODR_t*)(GPIO_BASE+0x0C);
unsigned char array[]={13,14,5,4,3};
vuint_t var1, var2;
int main(){
	volatile int i;
	APP2ENR |= 1<<2;
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;
	while(1){
		P_ODR->S_ODR.p_13 =1;
		for(i=0;i<5000;i++);
		P_ODR->S_ODR.p_13 =0;
		for(i=0;i<5000;i++);
	}
}
