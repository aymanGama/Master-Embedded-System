/*A2_Q5 (know if the input character or not)
 * main.c
 *  Created on:20/7/2022
 *      Author:Ayman-Gamal
*/
#include"stdio.h"
void main (){
	char a ;
	printf("Enter character :",a);
	fflush (stdout);
	scanf ("%c",&a);
	if (((a >='a')&&(a<='z'))||((a >='A')&&(a<='Z')))
		printf ("%c is alphabet ",a);
	else
		printf ("%c is not alphabet ",a);




}

