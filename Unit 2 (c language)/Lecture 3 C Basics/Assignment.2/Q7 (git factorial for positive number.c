/*A2_Q7 (git factorial for positive number )
 * main.c
 *
 *  Created on:20/7/2022
 *      Author:Ayman-Gamal
 */
#include"stdio.h"
void main(){
	int x;
	int i=1;
	int fact=1;
	printf ("Enter integer Number :  ");
	fflush(stdout);
	scanf ("%d",&x);
	if (x>0){
		for(i;i<=x;i++){
			fact*=i;
		}
		printf("factorial of %d =%d",x,fact);
	}
	else
		printf ("error !!!!!factoial of negative number dosnt exist");

}

