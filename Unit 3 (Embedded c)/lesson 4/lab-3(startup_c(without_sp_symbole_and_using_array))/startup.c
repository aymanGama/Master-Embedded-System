//startup c
#include <stdint.h>
extern int main();

void _reset (void) ;

void Default_Vectors(void){
	_reset();
}  

void NMI_fault ()__attribute__((weak, alias ("Default_Vectors")));
void Hard_Faukt ()__attribute__((weak, alias ("Default_Vectors")));
static unsigned long stack_top[256] ;
unsigned long vactors[]__attribute__((section(".vectors")))={
	(unsigned long) (unsigned long)(stack_top+sizeof(stack_top)),
	(unsigned long) &_reset,
	(unsigned long) &NMI_fault,
	(unsigned long) &Hard_Faukt,
};

extern unsigned int  E_TEXT ;
extern unsigned int  S_DATA ;
extern unsigned int  E_DATA ;
extern unsigned int  S_BSS ;
extern unsigned int  E_BSS ;
void _reset (void) {
volatile int i ;
unsigned int Data_size =(unsigned char*) &E_DATA - (unsigned char*) &S_DATA;
unsigned int Bss_size =(unsigned char*) &E_BSS -(unsigned char*) &S_BSS; 
unsigned char* P_SRC =(unsigned char*)&E_TEXT;
unsigned char* P_DIS =(unsigned char*)&S_DATA;

for (i =0;i<Data_size;i++){
	*((unsigned char*)P_DIS++)=*((unsigned char*)P_SRC++);
}
 P_DIS= (unsigned char*)&S_BSS;
for( i = 0 ; i<Bss_size; i++){
	*((unsigned char*)P_DIS++)=(unsigned char)0;
}
main();}