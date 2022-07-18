/*A2_Q8 (simple calculator)
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ayman
 */
#include "stdio.h"
void main (){
	char a;
	float b,c;
	printf("Enter the first number : ");
	fflush(stdout);
	scanf ("%f",&b);
	printf("Enter operator : ");
	fflush(stdout);
	fflush(stdin);
	scanf ("%c",&a);
	printf("Enter the second number : ");
	fflush(stdout);
	scanf ("%f",&c);
	switch (a){
	case '+':
	{
		printf("%.1f",(b+c));
	break ;
	}
	case '-':
	{
			printf("%.1f",(b-c));
	break ;
	}
	case '*':
	{
			printf("%.1f",(b*c));
	break ;
	}
	case '/':
	{
			printf("%.1f",(b/c));
	break ;
	}
	default:
	printf("you have mistake in input");
	}
}

