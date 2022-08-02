 /*q2 factorial using recursion
 *
 *   Created on: 27/7/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
#include <stdlib.h>
int factorial ();
int main()
{                                          //ask user enter positive number >0
    int num , fact;
    printf ("Enter s positive integer : ");
    scanf ("%d",&num);
    printf("factorial of %d = %d",num, factorial(num));
    return 0;
}
int factorial (int x)           //function to return factorial
{
    if(x!=1)
        return x*factorial(x-1);
    else
        return 1;

}
