/*EX5 (a pointer to an array which contents are pointer to structure.)
 * main.c
 *         Created on:8/8/2022
 *                           Author:Ayman_Gamal
 */
#include <stdio.h>
struct Sstudent
{                   //structure contain pointer for name and integer
	char* name;
	int ID;
};
int main()
{
	struct Sstudent s1={"Ayman",298}, s2={"ali",323};
	struct Sstudent (* arr[])={&s1,&s2};   //array of pointer to structure
	struct Sstudent  (*(* pt)[])=&arr;        //pointer to array of pointer of structure
	printf("studen Name : %s \n",(**(*pt)).name);
	printf("studen id : %d",(*(*pt))->ID);
}
