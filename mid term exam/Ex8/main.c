/*Ex(8) mid term exam c function to take an array and reverse its elements)
 *
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main()
{
	int arr[100],temp,size,i,j;
	printf ("Enter size of array: ");
	fflush(stdout);
	scanf("%d",&size);
	printf ("Enter numbers : \n");
	fflush(stdout);
	for (i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	i=size-1;j=0;
		while (i>j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i--;j++;
		}
	printf("reverse is: ");fflush(stdout);
	for (i=0;i<size;i++)
		printf("%d ",arr[i]);
	return 0 ;}
