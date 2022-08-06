/*Ex(7) mid term exam (c function to sum numbers from 1 to 100(without loop)?
 *
 * main.c
 *
 *  Created on: 3/8/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int Fsum(int x);
int main()
{
	int sum ;
	sum=Fsum(100);
	printf ("%d",sum);
	return 0;
}
int Fsum(int x)
{
	if (x>0)
	return x+Fsum(x-1);
}
