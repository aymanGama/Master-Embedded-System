/*Ex(2) mid term exam (c function to take an integer number and calculate it's square root)
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
#include <math.h>
int main ()
{
	int num1; float num2;
	printf("Enter integer number : ");
	fflush(stdout);
	scanf("%d",&num1);
	num2=sqrt(num1);
	printf("square root of %d=%.3f",num1,num2);
}

