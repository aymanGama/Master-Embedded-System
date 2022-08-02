/* A3Q7 prog to find length of string
 *  Created on: 24/7/2022
 *      Author: Ayman-Gamal
 */
#include<stdio.h>
int main(){
	char str[100];
	int i;
	printf("Enter your string : ");
	fflush(stdout);
	gets(str);
	for(i=0;i<100;i++){
		if(str[i]=='\0')
			break;
	}
	printf("your string length is %d",i);
	return 0;
}

