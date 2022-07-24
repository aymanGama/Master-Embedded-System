#include <stdio.h>      //calc power of integer number using recursion
#include <stdlib.h>
int power();
int main()
{
	int num,pow,answer;
	printf("Enter base number : ");    //ask user to enter num and its power
	scanf ("%d",&num);
	printf("Enter power number (positive integer ): ");
	scanf ("%d",&pow);
	answer = power(num,pow);   // call function
	printf("%d",answer);
	return 0;
}
int power (int x ,int y)
{
	if (y!=0)
		return x*power(x,y-1);     //recursive function
	else
		return 1;
}
