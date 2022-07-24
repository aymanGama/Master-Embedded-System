#include <stdio.h>
#include <stdlib.h>
void reverse ();
int main()
{

	printf("Enter a sentence : ");
	reverse();
	return 0;
}
void reverse ()
{
	char sen;
	scanf("%c",&sen);
	if (sen!= '\n')
{
	reverse();
	printf("%c",sen);
}
}
