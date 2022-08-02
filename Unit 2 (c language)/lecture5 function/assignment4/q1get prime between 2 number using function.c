 /*q1 get prime between 2 number using function
 *
 *   Created on: 27/7/2022
 *      Author: Ayman-Gamal
 */

#include <stdio.h>
#include <stdlib.h>
int prime();           //prototype
int main()
{
	int a,b,i,test;                                      //main gets to number
	printf("Enter two numbers (intervals) : ");
	scanf("%d%d",&a,&b);
	for (i=a+1 ;i<b ;i++){
		test=prime (i);
		if (test ==0)
			printf("%d ",i);
	}
	return 0;
}
int prime (int x)
{
	int test =0; int i;
	if (x==2)
		test=1;
	else
	{
		for (i=2;i<=x/2;i++){
			if (x%i==0){
				test=1;;
				break;}
		}
	}
	return test;

}


