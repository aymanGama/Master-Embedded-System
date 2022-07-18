/* A2_Q3 (chose the bigger number) using (  ?   :   )
 *
 * main.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: ayman
 */
#include "stdio.h"
void main (){
	float a,b,c;
	printf("enter three numbers :");
	fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	((a>=b)?((a>=c)?printf("the biggent number is %.2f",a):printf ("the biggest number is %.2f",c)):((b>=c)?printf("the biggest number is %.2f",b):printf("the biggest number is %.2f",c)));
}

