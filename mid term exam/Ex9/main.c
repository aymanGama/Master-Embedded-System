/*Ex(9) mid term exam (c function to reverse words in string)
 *
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
void Char ();
int main()
{
	printf("Enter sentence : ");
	fflush(stdout);
	Char();
	return 0;}
void Char ()
{
	char a;
	scanf ("%c",&a);
	if (a!='\n')
	{
		Char(a);
		printf("%c",a);
	}
}
