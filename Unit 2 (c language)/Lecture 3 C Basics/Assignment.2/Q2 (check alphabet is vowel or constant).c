/* A2Q2 (check alphabet is vowel or constant)
 * main.c
*  Created on:20/7/2022
 *      Author:Ayman-Gamal
 */
#include <stdio.h>
void main (){
	char alph ;
	printf ("Enter an alphabet : ");
	fflush (stdout);
	scanf ("%c",&alph);
	if (alph == 'a')
		printf ("%c is a vowel", alph);
	else if (alph == 'e')
			printf ("%c is a vowel", alph);
	else if (alph == 'i')
			printf ("%c is a vowel", alph);
	else if (alph == 'o')
			printf ("%c is a vowel", alph);
	else if (alph == 'u')
			printf ("%c is a vowel", alph);
	else
		printf("%c is a constant",alph);
}

