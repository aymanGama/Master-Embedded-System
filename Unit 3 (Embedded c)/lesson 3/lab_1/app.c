#include "uart.h"
unsigned char string_buffer[100]="learn_in_deapth:Ayman";
unsigned char string_buffer2[100]="learn_in_deapth:Ayman";

void main(void)
{
	Uart_sending_string(&string_buffer[0]);
}