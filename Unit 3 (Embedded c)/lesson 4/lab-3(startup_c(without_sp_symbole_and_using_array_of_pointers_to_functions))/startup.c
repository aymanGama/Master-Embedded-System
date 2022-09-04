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

void (*const  g_p_fun_vectors [])()__attribute__((section(".vectors")))={
	(void(*)()) ((unsigned long)stack_top+sizeof(stack_top)),
				&_reset,
	 			&NMI_fault,
				&Hard_Faukt,
};

extern unsigned int  E_TEXT ;
extern unsigned int  S_DATA ;
extern unsigned int  E_DATA ;
extern unsigned int  S_BSS ;
extern unsigned int  E_BSS ;
void _reset (void) {
volatile int x ;
unsigned int Data_size =(unsigned char*) &E_DATA - (unsigned char*) &S_DATA;
unsigned int Bss_size =(unsigned char*) &E_BSS -(unsigned char*) &S_BSS; 
unsigned char* P_SRC =(unsigned char*)&E_TEXT;
unsigned char* P_DIS =(unsigned char*)&S_DATA;

for (x =0;x<Data_size;x++){
	*((unsigned char*)P_DIS++)=*((unsigned char*)P_SRC++);
}
 P_DIS= (unsigned char*)&S_BSS;
for( x = 0 ; x<Bss_size; x++){
	*((unsigned char*)P_DIS++)=(unsigned char)0;
}
main();}