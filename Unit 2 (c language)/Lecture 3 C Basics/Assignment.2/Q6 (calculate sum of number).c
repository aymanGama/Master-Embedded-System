/*A2_Q6 (calculate sum of number)
 * main.c
 *
 *  Created on:20/7/2022
 *      Author:Ayman-Gamal
 */
#include "stdio.h"
void main(){
	int a;
	int sum =0;
	int y=0;
	printf("Enter integer number :  ");
	fflush(stdout);
	scanf ("%d",&a);
	for (sum;sum<=a;sum++)
	{
		y+=sum;
	}
	printf ("sum of numbers = %d",y);
}


