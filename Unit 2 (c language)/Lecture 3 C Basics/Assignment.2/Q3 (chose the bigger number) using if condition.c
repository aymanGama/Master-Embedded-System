/* A2_Q3 (chose the bigger number) using if condition
 * main.c
 *
*  Created on:20/7/2022
 *      Author:Ayman-Gamal
 */
#include <stdio.h>
int main ()
{
	float a,b,c;
	printf ("Enter three numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	if (b>=a){
		if (b>=c)
			printf (" the biggest number is %.2f ",b);
		else
	        printf (" the biggest number is %.2f ",c);
	}
	else
	{
		if (a>=c)
			printf ("the biggest number is %.2f ",a);
		else
			printf ("the biggest number is %.2f",c);
	return 0;
	}


}

