/*A1_Q7 (Source Code to Swap Two Numbers without temp variable)
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ayman
 */
# include "stdio.h"
void main (){
	float val1, val2;
	printf ("enter two numbers : "); // ask user input two numbers
	fflush (stdout);
//	make \n between two %f two make user have ability to enter second num in new line
	scanf ("%f \n %f", &val1, &val2);
	val2= val2+val1 ; // sum two numbers and but in one of them
	val1= val2-val1; // sub one from total and but its value in second time value
	val2=val2-val1 ;
	printf ("two numbers are= %f ,%f",val1,val2); // with the samre arrenge for input but we will find it replace on out screeen
}


