/* A3Q3 transpose of a matrix
 * main.c
 *  Created on: 24/7/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main(){          //define variable
	float a[10][10],b[100][100];
	int n,m,i,k;
	printf ("Enter rows and column of matrix :  ");  //ask user to enter num of row and column
	fflush(stdout);fflush (stdin);
    scanf("%d%d",&n,&m);
    while (n<0||n>10||m<0||m>10){// enter any negative ,higher of 100 error
    	printf ("error you should enter number bigger than 0 and less than 100 \n");
    	printf(" Enter another row and column ");
		fflush (stdout);  fflush (stdin);
        scanf ("%d%d",&n,&m);                  //enter num of row and column again
    } printf("Enter elements of matrix :  \n");
    for (i=0;i<n;i++){                //loop to enter the matrix
    		for(k=0;k<m;k++){
    			printf("Enter a%d%d : ",i+1,k+1);
    			fflush(stdout);  fflush(stdin);
    			scanf("%f",&a[i][k]);}}
    printf("Entered matrix is: \n");   //print the entered matrix
    for (i=0;i<n;i++){
    		for(k=0;k<m;k++){
    			printf("\t%.2f",a[i][k]);
    		}
    		printf("\n");}
    for (i=0;i<n;i++){ //but matrix in another matrix with transposed
       		for(k=0;k<m;k++){
       			b[i][k]=a[i][k];}
       		}
    printf ("transposed matrix is : \n");  //print transposed matrix
    for (i=0;i<m;i++){
       		for(k=0;k<n;k++){
       			printf("\t%.2f",b[k][i]);
       		}printf("\n");}
 return 0;}

