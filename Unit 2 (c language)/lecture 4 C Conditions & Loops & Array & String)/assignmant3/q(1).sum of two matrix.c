/* sum of two matrix in order 2*2 get elements from user and put it in sum matrix
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ayman Gamal
 */
#include<stdio.h>
int main(){
	//name of variable
	int i,k;
	float a[2][2],b[2][2],sum[2][2];
	//user is entering elements of first matrix
	printf("Enter elements of first matrix   : \n");
	for (i=0;i<2;i++){
		for(k=0;k<2;k++){
			printf("Enter a%d%d : ",i+1,k+1);
			fflush(stdout);  fflush(stdin);
			scanf("%f",&a[i][k]);
		}
	}//user enter second matrix element
	printf("\nEnter elements of second matrix   : \n");
	for (i=0;i<2;i++){
		for(k=0;k<2;k++){
			printf("Enter b%d%d : ",i+1,k+1);
			fflush(stdout);  fflush(stdin);
			scanf("%f",&b[i][k]);
		}
}                            // make sum for two matrix and but them in sum array
	for (i=0;i<2;i++){
		for(k=0;k<2;k++){
			sum[i][k]=a[i][k]+b[i][k];
		}
	}
	printf("the sum of two matrix  : \n");
	for (i=0;i<2;i++){                //print the value of sum matrix
		for(k=0;k<2;k++){
			printf("\t%.2f",sum[i][k]);
		}
		printf("\n");
	}
return 0;
}







