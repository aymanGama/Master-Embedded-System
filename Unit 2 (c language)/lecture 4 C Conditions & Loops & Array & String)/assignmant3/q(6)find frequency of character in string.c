/*A3Q6 find frequency of character in string
 * maon.c
 *  Created on: 24/7/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
int main(){
	int x=0,i;
	char str[100],character;
	printf("Enter a string : ");
	fflush(stdout);
	gets(str);
	printf("Enter a character to find its frequency : ");
	fflush(stdout);
	scanf("%c",&character);
	for(i=0;i<100;i++){
		if(character==str[i])
			x+=1;

	}
	printf("frequency of %c = %d",character,x);
	return 0;
}

