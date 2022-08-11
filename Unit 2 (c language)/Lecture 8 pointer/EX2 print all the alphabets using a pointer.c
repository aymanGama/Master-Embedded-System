/*EX2 (print all the alphabets using a pointer Go to the editor)
 * main.c
 *         Created on:8/8/2022
 *                           Author:Ayman_Gamal
 */
#include <stdio.h>
int main()
{
	char characters[26];
	char* Alphabet;
	Alphabet = characters;        //Alphabet pointer point on first address of string
	int i=0;
	for (i=0 ;i<26;i++)
	{                        //  store string with characters using pointer
		*Alphabet=i+'A';
		Alphabet++;
	} Alphabet = characters;    // return pointer to point to first address of string
	for(i=0;i<26;i++)                   //print string of character using pointer
	{
		printf("%c ",*Alphabet);
		Alphabet++;
	} return 0;
}

