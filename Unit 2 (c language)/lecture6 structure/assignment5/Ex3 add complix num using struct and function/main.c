#include <stdio.h>
#include <stdlib.h>
struct Scomplex
{
    float Real;
    float Img;
};
struct Scomplex Readcomplex(char name[])
{
    struct Scomplex read;
    printf("Enter %s real and imaginary respectively  ",name);
    scanf("%f%f",&read.Real,&read.Img);
    return read;
};
struct Scomplex Addcomplex (struct Scomplex num1,struct Scomplex num2)
{
    struct Scomplex sum;
    sum.Real=num1.Real+num2.Real;
    sum.Img=num1.Img+num2.Img;
    return sum;
};
int main()
{
    struct Scomplex num1, num2, sum;
    printf("For first number\n");
    num1=Readcomplex("first number");
    printf("For second number\n");
    num2=Readcomplex("second number");
    sum=Addcomplex(num1,num2);
    printf("sum of two number = %.1f+(%.1fi)",sum.Real,sum.Img);
}
