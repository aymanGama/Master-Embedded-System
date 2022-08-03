/*Ex(4) mid term exam (c function to reverse digits in number)
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main()
{
	int num,i,rev=0;
	printf("Enter number to reverse : ");
	fflush (stdout);
	scanf("%d",&num);
	for(i=num;i>0;i/=10)
	{
		rev=rev * 10;
		rev=rev + i%10;
	}
	printf("reverse number is %d",rev);
}

