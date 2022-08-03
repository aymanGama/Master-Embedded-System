/*Ex(10) mid term exam (c function to count the max number of ones between two zeros)
 *
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main()
{
	int test[100],num,i,j,x,max,count;
	printf ("Enter the number : ");
	fflush (stdout);
	scanf("%d",&num);
	i=0;
	while (num>0)
	{
		test[i]=num%2;
		num/=2;
		i++;
	}
	test[i]=0;
	x=i;max=0,count=0;
	for(i=0;i<=x;i++)
	{
		if (test[i]==0)
		{
			for (j=i+1;j<=x;j++)
			{
				if(test[j]==0)
				{
					count=j-i-1;
					break;
				}
			}
			if (count>=max)
				max=count;
		}
	}
	printf("max number of ones between two zero is : %d",max);
}
