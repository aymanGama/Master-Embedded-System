/*EX3 (print a string in reverse using a pointer)
 * main.c
 *         Created on:8/8/2022
 *                           Author:Ayman_Gamal
 */
#include <stdio.h>
int main()
{
	int i;
	char* Pa;
	char a[100];
	printf("input a string : ");
	fflush(stdout);
	gets(a);
	int x=strlen(a)-1;
	Pa=&a[x];
	printf ("Reverse of the string is : ");
	for(i=x;i>=0;i--)
	{
		printf("%c",*Pa);
		Pa--;
	} return 0;
}
