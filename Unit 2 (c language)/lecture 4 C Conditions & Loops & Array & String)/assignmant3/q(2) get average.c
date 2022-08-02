/* get average for n numbers  entered by user
 * main.c
 *
 *  Created on: 24/7/2022
 *      Author: Ayman-Gamal
 */
#include<stdio.h>
int main(){
	int i,n; float average ,sum ;   //define variable
	float avr[100];
	printf("Enter the number of elements : ");
	fflush (stdout);  fflush (stdin);   //ask user to give number
	scanf("%d",&n);
	if (n<=0 || n>100 ){
		printf("error you should inter number from 0 t0 100");
	}
	else if (0<n&&n<=100){
	for(i=0;i<n;i++){
		printf("Enter number N%d : ",i+1);
		fflush (stdout);  fflush (stdin);
		scanf("%f",&avr[i]);
	}
	for(i=0,sum=0;i<n;i++){            //sum  array numbers
		sum+=avr[i];
		}
	average = sum/n;                  //get average and print it
	printf("\n the average for %d numbers =  %.2f",n,average);
	}
return 0; }
