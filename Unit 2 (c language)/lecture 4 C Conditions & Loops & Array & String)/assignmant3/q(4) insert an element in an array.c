/* A3Q4 insert an element in an array
 * main.c
 *      Author: ayman
 */
#include <stdio.h>
int main(){                               // define variable
	int a[100];  int i,l,n,e;
	printf("Enter the number of elements : \n");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);               //user enter number of elements
	printf("Enter elements : ");
	for(i=0;i<n;i++){
		fflush(stdout);fflush(stdin);
		scanf("%d",&a[i]);             // user enters elements
	}
	printf("Enter element to be inserted : ");
	fflush(stdout);fflush(stdin);
    scanf("%d",&e);                          //enter instead element and location
    printf ("Enter the location : ");
    fflush(stdout);fflush(stdin);
    scanf("%d",&l);
    for(i=0;i<n;i++){                        // for loop print until reach location
    	if(i==(l-1))
    		break;                         // break to print insert element
    	printf("%d",a[i]);}
    printf("%d",e);
    for(l-=1;l<n;l++)                      // for loop to print other element after insert
    {
    	printf("%d",a[l]);
    }
	return 0;
}
