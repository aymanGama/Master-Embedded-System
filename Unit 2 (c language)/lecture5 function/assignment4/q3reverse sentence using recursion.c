 /*q3 reverse sentence using recursion
 *
 *   Created on: 27/7/2022
 *      Author: Ayman-Gamal
 */
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
