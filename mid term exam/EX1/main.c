/*Ex(1) mid term exam (sum digits for input number)
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main ()
{
	int sum=0,num;
	printf("Enter integer number : ");
	fflush(stdout);
	scanf("%d",&num);
	while (num>0)
	{
		sum+=num%10;
		num=num/10;
	}
	printf("sum of digit for number = %d",sum);
	return 0;
}

