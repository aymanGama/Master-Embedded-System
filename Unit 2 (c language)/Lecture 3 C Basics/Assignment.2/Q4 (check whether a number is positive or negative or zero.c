/* A2_Q4 (check whether a number is positive or negative or zero)
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: ayman
 */
#include"stdio.h"
void main(){
	float num ;
	printf("Enter the number :  ");
	fflush(stdout);
	scanf("%f",&num);
	if(num<0)
		printf("%.2f is negative",num);
	else if (num>0)
		printf("%.2f is positive ",num);
	else
		printf (" you entered Zero");
 }

