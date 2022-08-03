/*Ex(3) mid term exam (c function to print all prime numbers between two numbers)
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int prime ();
int main ()
{
	int num1,num2,i,check;
	printf("Enter two  integer numbers : \n");
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	fflush(stdin);
	printf ("prime numbers between %d and %d =[ ",num1,num2);
	for (i=num1 ;i<=num2;i++)
	{
		check=prime(i);
		if (check==0)
			printf ("%d ",i);
	}
	printf("]");
	return 0;
}
int prime (int x)
{
	int i,j,check=0;
	for (j=2;j<=x/2;j++)
	{
		if(x%j==0)
		{
			check=1;
			break ;
		}
}    return check;
}
