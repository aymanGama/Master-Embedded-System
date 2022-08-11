/*EX5 macro (find area of a circle passing arguments to macros)
 * main.c
 *
 *  Created on:4/8/2022
 *      Author: Ayman_Gamal
 */
#include <stdio.h>
#define pi 3.14
#define Area(x,...) printf(__VA_ARGS__,(pi*x*x))
int main ()
{
	float radius;
	printf("Enter The radius: ");
	fflush(stdout);
	scanf("%f",&radius);
	Area(radius,"area=%.2f");
}

