//startup c
#include <stdint.h>
extern int main();

void _reset (void) ;

void Default_Vectors(void){
	_reset();
}  

void NMI_fault ()__attribute__((weak, alias ("Default_Vectors")));
void Hard_Faukt ()__attribute__((weak, alias ("Default_Vectors")));
void MM_Fault ()__attribute__((weak, alias ("Default_Vectors")));
void Bus_fault ()__attribute__((weak, alias ("Default_Vectors")));
void Usage_Fault ()__attribute__((weak, alias ("Default_Vectors")));
void RESERVED ()__attribute__((weak, alias ("Default_Vectors")));
extern unsigned int stck_top ;
uint32_t vactors[]__attribute__((section(".vectors")))={
	(uint32_t) &stck_top,
	(uint32_t) &_reset,
	(uint32_t) &NMI_fault,
	(uint32_t) &Hard_Faukt,
	(uint32_t) &MM_Fault,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_Fault,
	(uint32_t) &RESERVED,
};
int i;
extern unsigned int  E_TEXT ;
extern unsigned int  S_DATA ;
extern unsigned int  E_DATA ;
extern unsigned int  S_BSS ;
extern unsigned int  E_BSS ;
void _reset (void) {

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