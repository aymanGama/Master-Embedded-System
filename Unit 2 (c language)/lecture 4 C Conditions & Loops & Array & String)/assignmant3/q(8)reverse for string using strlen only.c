/*A3Q8 reverse for string using strlen only from library
 *     Author: Ayman
 */
#include <stdio.h>
#include<string.h>
int main(){
	int x,i=0;
	char str[100],rev[100];
	printf ("Enter a string: ");
	fflush(stdout);
	scanf("%s",str);
	x=strlen(str);
	rev[x]='\0';x--;
	for (i=0;i<=x;i++)
		rev[x-i]=str[i];
	printf(" the reverse is : %s",rev);
	return 0;
}

