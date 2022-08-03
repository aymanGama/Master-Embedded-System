/*Ex(6) mid term exam (c function to return unique number in array with one loop)
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main()
{
	int arr[10],check[10];
	int size,i,j;
	printf("Enter size of array : ");
	fflush(stdout);
	scanf("%d",&size);
	printf("Enter element of array : ");
	for (i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
		check[i]=0;
	}
	for (i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if (arr[i]==arr[j])
			{
				check[i]=1;
				check[j]=1;
			}
		}
		if (check[i]==0)
			printf("the unique number is : %d",arr[i]);
	}
}
