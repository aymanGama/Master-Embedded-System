/*(A1)(Q6)(Source Code to Swap Two Numbers)
 * main.c
 *
 *  Created on:18/7/2022
 *      Author: Ayman-Gamal
 */
#include "stdio.h"
void main(){
	float a,b,x,y;
	printf ("Enter value of a: ");
	fflush (stdout);
	scanf ("%f",&a);
	printf ("Enter value of b: ");
	fflush (stdout);
	scanf ("%f",&b);
	x=a,y=b;
	a=y,b=x;
	printf ("value of a = %f \r\n ", a);
	printf ("value of b = %f \r\n", b);
}

