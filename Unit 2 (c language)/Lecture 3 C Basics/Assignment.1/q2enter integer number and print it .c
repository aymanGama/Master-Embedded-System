/*(Q2-A1) enter integer number and print it
 * main.c
 *
 *  Created on: 18/7/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
void main (){
	int num;
	printf ("Enter a integer: ");
	fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);
	printf ("You entered: %d",num);
}

