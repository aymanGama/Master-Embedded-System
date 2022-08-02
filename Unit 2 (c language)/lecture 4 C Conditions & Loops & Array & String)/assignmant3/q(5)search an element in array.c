/* A3Q5 search an element in array
 * main.c
 *  Created on: 24/7/2022
 *      Author: Ayman-Gamal
 */
#include<stdio.h>
int main (){
	int e ,n,i;
	int a[10];
	printf ("Enter number of element for array : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);
	while (n<=0||n>10){
		printf("error enter number positive and >10\n");
		printf("Enter number of element for array : ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&n);
	}
	fflush(stdout);fflush(stdin);
	printf ("Enter  value of elements :  ");
	fflush(stdout);fflush(stdin);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	}
	printf ("Enter  element to search on it: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&e);
	i=0;
	while (i<n&&e!=a[i])
	{
		i++;
	}

	if (i<n){
		printf("number found at location %d",i+1);}
	else
		printf("number is not found");
	return 0;
}

