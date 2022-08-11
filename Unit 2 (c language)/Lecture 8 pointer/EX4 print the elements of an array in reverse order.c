/*EX4 (print the elements of an array in reverse order using pointer)
 * main.c
 *         Created on:8/8/2022
 *                           Author:Ayman_Gamal
 */
#include <stdio.h>
int main()
{
	int arr[15],i,size;
	int* Parr =arr;
	printf("Input the number of elements to store in the array (max 15) :"); fflush(stdout);
	scanf("%d",&size);
	printf("Input %d number of elements in the array : \n",size);
	for(i=0;i<size;i++)
	{
		printf("Enter element-%d:",i+1); fflush(stdout);
		scanf("%d",Parr);
		Parr++;
	}
	printf("The elements of array in reverse order are : \n");
	for(i=i-1;i>=0;i--)
	{	Parr--;
		printf("element -%d : %d \n",i+1,*Parr);
	}
	return 0 ;
}


