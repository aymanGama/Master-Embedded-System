/*Ex(5) mid term exam (c function to count number of ones in binary number)
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int getone();
int main()
{
	int sum , num;
	printf("Enter integer number : ");
	fflush(stdout);
	scanf("%d",&num);
	sum=getone(num);
	printf ("%d contain %d ones",num,sum);
	return 0;
}
int getone(int x)
{
	int count=0 ,i;
	for(i=x;i>0;i/=2)
	{
		if (i%2==1)
			count++;
	}
    return count;
}
