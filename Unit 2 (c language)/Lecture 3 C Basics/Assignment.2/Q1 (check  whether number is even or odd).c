/*A2_Q1 (check  whether number is even or odd)
 * main.c
 *  Created on: ??�/??�/????
 *      Author: ayman
 */
#include "stdio.h"
int main (){
	int n;
	printf ("Enter integer number : ");
	scanf ("%d ",&n);
	if ((n %2) == 1 )
		printf ("%d is odd number ", n );
	else
		printf("%d is even number ", n);
	return 0;
}
