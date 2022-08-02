#include <stdio.h>
#include <stdlib.h>
struct SDustance {
    int Feet;
    float Inch;
    };
int main()
{
    struct SDustance First,second,sum;
    printf("Enter information for 1st distance : \n");
    printf("Enter feet : ");
    scanf("%d",&First.Feet);
    printf("Enter inch : ");
    scanf("%f",&First.Inch);
    printf("Enter information for 2nd distance : \n");
    printf("Enter feet : ");
    scanf("%d",&second.Feet);
    printf("Enter inch : ");
    scanf("%f",&second.Inch);
    sum.Feet=First.Feet+second.Feet;
    sum.Inch=First.Inch+second.Inch;
    while(sum.Inch>=12)
    {
        sum.Feet++;
        sum.Inch-=12;
    }
    printf ("sum of distance = %d\'-%.1f\"",sum.Feet,sum.Inch);
    return 0;
}
